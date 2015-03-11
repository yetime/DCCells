/*
 * oc.c
 *
 *  Created on: 2 Dec 2014
 *      Author: Christine
 *
 */



#include "header.h"
#include "oc_agent_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "stuff.h"

#define OC_DEATH_SIG 1
#define OC_FUSE_SIG 2

int initialize_oc(){
	OC_AGE=1;
	return 0;
}

/*
 * Announces the current position to the agents in the system
 */
int signal_oc_position(){
	if(OC_AGE!=0) {
		add_oc_position_message(OC_DIM,OC_ID, OC_MYBMU);
	}
		return 0;
}

int signal_oc_updated_position(){
	if(OC_AGE!=0){
		add_oc_updated_position_message(OC_DIM,OC_ID, OC_MYBMU);
	}
	return 0;
}

/*
 * Increments the age  of a cell, increments the probability for celldeath in a window
 * of +- 2 days around the maximum age
 */
int oc_get_older(){
	//int min=OC_LIFESPAN-2*OC_LIFESPAN;
	//int max=OC_LIFESPAN-2*OC_LIFESPAN;

	//if (min<0) min=0;
	//if(OC_AGE>min && OC_AGE<=max){
	//	OC_DEATH_PROB=OC_DEATH_PROB+1/OC_LIFESPAN;
	//}
	OC_AGE=OC_AGE+1;
	return 0;
}


/*
 * Kills an agent if it reaches its maximum age or a bit earlier based on probability that increases (atm linear)
 * over the last two days of a cells life
 */
int oc_die(){
	if(OC_AGE>OC_LIFESPAN){
		if(OC_DIM.nuclei>1){
			OC_DIM.diameter=OC_DIM.diameter-OC_DIAMETER;
			OC_DIM.nuclei=OC_DIM.nuclei-1;
			OC_AGE=OC_AGE/3;
			add_death_message(OC_MYBMU, OC_TYPE);
			return 0;
		}
		else {
			add_death_message(OC_MYBMU, OC_TYPE);
			return 1;
		}
	}
	else return 0;
}

int fuse(){
	START_FUSION_SIGNAL_MESSAGE_LOOP
		if(fusion_signal_message->id1==OC_ID && fusion_signal_message->f_bmu_id==OC_MYBMU){
			if(fusion_signal_message->f_signal==FUSION_DEL) return 1;
			else {
				OC_DIM.nuclei=OC_DIM.nuclei+fusion_signal_message->f_nuclei;
				double dia=(2*PI*OC_DIM.diameter/2+2*PI*fusion_signal_message->second_diameter/2)/PI;
				OC_DIM.diameter=dia;
				return 0;
			}
		}
	FINISH_FUSION_SIGNAL_MESSAGE_LOOP
	return 0;
}

/*
 * Moves the osteoclasts in the same direction as the BMU randomly asigned BMU direction... (later on: along microcracks?
 */
int oc_move(){
	//determine new position and put a bit of randomization onto it

	int bmu_x=OC_DIM.xy.x;
	int bmu_y=OC_DIM.xy.y;



	START_BMU_POSITION_MESSAGE_LOOP
		if(bmu_position_message->bmu_id==OC_MYBMU){
			bmu_x=bmu_position_message->bmu_pos.x;
			bmu_y=bmu_position_message->bmu_pos.y;
		}
	FINISH_BMU_POSITION_MESSAGE_LOOP

	double current_x=OC_DIRECTION.x;
	double current_y=OC_DIRECTION.y;

	double offset_x=rnd_numbers_normal(OC_DISPL_STDEV);
	double offset_y=rnd_numbers_normal(OC_DISPL_STDEV);

	double new_x=current_x;
	double new_y=current_y;

	double alpha = atan(new_y/new_x);

	double bmu_dist=eucl_distance(OC_DIM.xy.x, OC_DIM.xy.y, bmu_x, bmu_y);

	double new_speed=OC_SPEED;
	double angle_offset=0;
	if(bmu_dist>=OC_MAX_FRONTDIST && bmu_dist!=0){
		new_speed=OC_SPEED/OC_DIM.nuclei;
		angle_offset=PI/2;
		if(rnd_numbers()>0.5) angle_offset=angle_offset*-1;
	}
	else if (bmu_dist<OC_MAX_FRONTDIST &&  OC_MAX_FRONTDIST-bmu_dist>=1) {
		//exponential decay...
		new_speed=OC_SPEED*exp(-OC_SPEED_DAMP*bmu_dist);
	}
	new_y=sin(alpha+angle_offset)*new_speed+offset_y;
	new_x=cos(alpha+angle_offset)*new_speed+offset_x;


	if(current_x<0 && current_y<0) {
		new_x=new_x*-1;
		new_y=new_y*-1;
	}
	else if(current_x<0 && current_y>0){
		new_x=new_x*-1;
		new_y=new_y*-1;
	}

	OC_DIM.xy.x=OC_DIM.xy.x+new_x;
	OC_DIM.xy.y=OC_DIM.xy.y+new_y;


	return 0;
}

int oc_update_position(){
		START_NEW_OC_POSITION_MESSAGE_LOOP
			if(new_oc_position_message->push_id==OC_ID){
				OC_DIM.xy.x=new_oc_position_message->dims.xy.x;
				OC_DIM.xy.y=new_oc_position_message->dims.xy.y;
			}
		FINISH_NEW_OC_POSITION_MESSAGE_LOOP

		return 0;
	return 0;
}

/*int move(){
	printf("OC move\n");

		//The four points on the cell surface were the concentration is measured
		int x1=GEO.xcoord+GEO.length/2;

	    printf("X1: %d\n", x1);
		int y1=GEO.ycoord;

	    int x2=GEO.xcoord+GEO.length;
	    int y2=GEO.ycoord+GEO.length/2;

	    int x3=GEO.xcoord+GEO.length/2;
	    int y3=GEO.ycoord+GEO.length;

	    int x4=GEO.xcoord;
	    int y4=GEO.ycoord+GEO.length/2;

	    START_POINTSOURCE_MESSAGE_LOOP
	    //From Wu, D. and Lin F. 2011: L=Lmax/A^n*(A-rho)^n+L0
	    int psx=pointsource_message->location.locationx;
	    int psy=pointsource_message->location.locationy;
	    int lmax=pointsource_message->location.current_conc;
	    int l0=pointsource_message->location.base_conc;
	    int A=WORLDSIZE/2;
	    int n=pointsource_message->location.gradient_power;

	    double L1=pow(lmax/A,n)*pow((A-eucl_distance(x1,y1,psx,psy)),n)+l0;
	    double L2=pow(lmax/A,n)*pow((A-eucl_distance(x2,y2,psx,psy)),n)+l0;
	    double L3=pow(lmax/A,n)*pow((A-eucl_distance(x3,y3,psx,psy)),n)+l0;
	    double L4=pow(lmax/A,n)*pow((A-eucl_distance(x4,y4,psx,psy)),n)+l0;

	    double max1=0;
	    double max2=0;

	    int positionx=1;
	    int positiony=1;

	    if(L1>max1) max1=L1;
	    if(L2>max1){
	    	max1=L2;
	    	max2=L1;
	    }
	    else max2=L2;

	    if (L3>max1){
	    	max2=max1;
	    	max1=L3;
	    	positiony=-1;
	    }
	    else if (L3>max2) {
	    	max2=L3;
	    	positiony=-1;
	    }

	    if(L4>max1){
	    	max2=max1;
	    	max1=L4;
	    	positionx=-1;
	    }
	    else if (L4>max2) {
	    	max2=L4;
	    	positionx=-1;
	    }
	    double displacementx=cos(max1/(max1+max2))*OC_SPEED+positionx;
	    double displacementy=cos(max2/(max1+max2))*OC_SPEED+positiony;

	    printf("displacementx %f", displacementx);
	    printf("displacementy %f", displacementy);

	    GEO.xcoord=displacementx;
	    GEO.ycoord=displacementy;

	FINISH_POINTSOURCE_MESSAGE_LOOP
	return 0;
}
*/

