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
#include <time.h>
#include <math.h>

double eucl_distance(int x1, int x2, int y1, int y2);

int signal_oc_position(){
	printf("OC signal\n");
	add_position_message(GEO,1);
	return 0;
}

int move(){
	printf("OC move\n");

		//The four points on the cell surface were the concentration is messured
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

double eucl_distance(int x1, int y1,int x2, int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
