/*
 * bmu.c
 *
 *  Created on: 17 Dec 2014
 *      Author: yeti
 */


#include "header.h"
#include "bmu_agent_header.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "stuff.h"


/*
 * Create new osteoblast and osteoclast agents, but only if a OB or OC id message is present (which in turn depends
 * on the outcome of request ids and rnd numbers
 */

int replace_fusion_pair(dim_id cell1, dim_id cell2, fusion_pair_array fusp, double overlap);
double cellid_in_array(fusion_pair_array fusp, int cellid);

/*! \brief Creation of Osteoblast and Osteoclast agents.
 *
 * Osteoblasts and Osteoclasts are generated based on their given creation frequency in the models startup file.
 */
int create(){

		if(BMU_AGE<=BMU_LIFESPAN+BMU_SPEED*OC_MAX_FRONTDIST){
		double rnd_ob=rnd_numbers();
		double rnd_oc=rnd_numbers();

		//OB creation
		if(rnd_ob<OB_CREATION_FREQ && BMU_AGE>=216 && Z<=100)
		{
			coordinate ob_pos;
			init_coordinate(&ob_pos);
			ob_pos.x=BMU_POSITION.x;
			ob_pos.y=BMU_POSITION.y;
			celldim ob_dim;
			init_celldim(&ob_dim);
			ob_dim.xy=ob_pos;
			ob_dim.diameter=OB_DIAMETER;
			ob_dim.nuclei=1;
			add_ob_agent(ob_dim,0,get_new_ob_id(),0, BMU_ID, BMU_DIRECTION, FALSE);
			OB_PRESENT=OB_PRESENT+1;
		}

		//Osteoclast creation
		if(rnd_oc<OC_CREATION_FREQ&& BMU_AGE<BMU_LIFESPAN-OC_MAX_FRONTDIST*BMU_SPEED){
			coordinate oc_pos;
			init_coordinate(&oc_pos);
			oc_pos.x=BMU_POSITION.x;
			oc_pos.y=BMU_POSITION.y;
			celldim oc_dim;
			init_celldim(&oc_dim);
			oc_dim.xy=oc_pos;
			oc_dim.diameter=OC_DIAMETER;
			oc_dim.nuclei=1;
			coordinate oc_dir;
			init_coordinate(&oc_dir);
			oc_dir.x=BMU_DIRECTION.x;
			oc_dir.y=BMU_DIRECTION.y;
			add_oc_agent(oc_dim,0,get_new_oc_id(), 0, BMU_ID, oc_dir);
			OC_PRESENT=OC_PRESENT+1;
		}
	}

	return 0;
}

/*! \brief Removal of BMU agents based on their age
 *
 */

int bmu_die(){

	if (Z>=100 && BMU_AGE>=BMU_LIFESPAN+OC_MAX_FRONTDIST*BMU_SPEED)
		return 1;
	if (BMU_AGE>=BMU_LIFESPAN && Z>=100) BMU_SPEED=0;
	return 0;
}

/*! \brief Moves the BMU
 *  Determines the new position of the capilary tip of the BMU as given by the speed and direction of the BMU in the configuration file
 */

int bmu_move(){
	double alpha = atan(BMU_DIRECTION.y/BMU_DIRECTION.x);


	double new_y=sin(alpha)*BMU_SPEED;
	double new_x=cos(alpha)*BMU_SPEED;



		if(BMU_DIRECTION.x<0 && BMU_DIRECTION.y<0) {
			new_x=new_x*-1;
			new_y=new_y*-1;
		}
		else if(BMU_DIRECTION.x<0 && BMU_DIRECTION.y>0){
			new_x=new_x*-1;
			new_y=new_y*-1;
		}
		BMU_POSITION.x=BMU_POSITION.x+new_x;
		BMU_POSITION.y=BMU_POSITION.y+new_y;

	return 0;
}

/*! \brief Determines whether two osteoclasts fuse
 * Fusing pairs of Osteoclasts are determined based on their current positions and overlap. Fusion
 * messages are generated to notify the corresponding osteoclasts of the fusion event, one of the agents receives
 * a death message, while the other takes up its nuclei and grows in size.
 */
int calc_fusions(){
	dim_id_array bmu_ocs;
	init_dim_id_array(&bmu_ocs);

	celldim d;
	init_celldim(&d);

	START_OC_POSITION_MESSAGE_LOOP
	    if(oc_position_message->bmu_scope==BMU_ID) {
	    	copy_celldim(&oc_position_message->oc_dimension, &d);
	    	add_dim_id(&bmu_ocs, &d, oc_position_message->id);
	    }
	FINISH_OC_POSITION_MESSAGE_LOOP


	fusion_pair_array fusp;
	init_fusion_pair_array(&fusp);

	int i,j, sum_nuclei;
	double x1, x2, y1, y2;
	double dist, sum_radii, overlap, old_overlap_i, old_overlap_j;

	for(i=0;i<bmu_ocs.size;i++){
		for(j=0;j<bmu_ocs.size;j++){
			x1=bmu_ocs.array[i].dims.xy.x;
			y1=bmu_ocs.array[i].dims.xy.y;
			x2=bmu_ocs.array[j].dims.xy.x;
			y2=bmu_ocs.array[j].dims.xy.y;

			dist=eucl_distance(x1, y1, x2, y2);
			sum_radii=bmu_ocs.array[i].dims.diameter/2+bmu_ocs.array[j].dims.diameter/2;
			sum_nuclei=bmu_ocs.array[i].dims.nuclei + bmu_ocs.array[j].dims.nuclei;

			if(dist-sum_radii<0 && dist>0 && sum_nuclei<OC_MAX_NUCLEI){
				overlap=sum_radii-dist;

				old_overlap_i=cellid_in_array(fusp, bmu_ocs.array[i].id);
				old_overlap_j=cellid_in_array(fusp, bmu_ocs.array[j].id);

				if(old_overlap_i<0 && old_overlap_j<0) {
					add_fusion_pair(&fusp, bmu_ocs.array[i].id, &bmu_ocs.array[i].dims, bmu_ocs.array[j].id, &bmu_ocs.array[j].dims, overlap);
				}
				else if(old_overlap_i<overlap || old_overlap_j<overlap){
					replace_fusion_pair(bmu_ocs.array[i], bmu_ocs.array[j], fusp, overlap);
				}

			}
		}
	}

	for(i=0;i<fusp.size;i++){
		add_fusion_signal_message(fusp.array[i].id1, FUSION_FUSE,BMU_ID, fusp.array[i].dim2.nuclei,fusp.array[i].dim2.diameter);
		add_fusion_signal_message(fusp.array[i].id2, FUSION_DEL, BMU_ID,0,0);
	}

	free_celldim(&d);
	free_dim_id_array(&bmu_ocs);
	return 0;
}

int replace_fusion_pair(dim_id cell1, dim_id cell2, fusion_pair_array fusp, double overlap){
	int i;
	for(i=0;i<fusp.size;i++){
		if((cell1.id==fusp.array[i].id1 && cell2.id==fusp.array[i].id2) || (cell2.id==fusp.array[i].id1 && cell1.id==fusp.array[i].id2)){
			fusp.array[i].id1=cell1.id;
			fusp.array[i].dim1=cell1.dims;
			fusp.array[i].id2=cell2.id;
			fusp.array[i].dim2=cell2.dims;
			fusp.array[i].overlap=overlap;
			return 0;
		}
	}
	return 0;
}

double cellid_in_array(fusion_pair_array fusp, int cellid){
	double overlap=-1;

	int i;
	for(i=0;i<fusp.size;i++){
		if(cellid==fusp.array[i].id1 || cellid==fusp.array[i].id2){
			return fusp.array[i].overlap;
		}
	}
	return overlap;

}

int ob_push_check(){
	dim_id_array bmu_obs;
	init_dim_id_array(&bmu_obs);

	celldim d;
	init_celldim(&d);

	START_OB_POSITION_MESSAGE_LOOP
		copy_celldim(&ob_position_message->ob_dimension, &d);
		add_dim_id(&bmu_obs,&d,ob_position_message->id);
	FINISH_OB_POSITION_MESSAGE_LOOP

	int solved=FALSE;
	int iterations_threshold=0;
	int i,j;
	double x1,y1,x2,y2;
	double new_x, new_y, alpha, overlap, dist, sum_radii;

	while(solved==FALSE && iterations_threshold<1000000){

		solved=TRUE;
		for(i=0;i<bmu_obs.size;i++){
			for(j=0;j<bmu_obs.size;j++){
				x1=bmu_obs.array[i].dims.xy.x;
				y1=bmu_obs.array[i].dims.xy.y;
				x2=bmu_obs.array[j].dims.xy.x;
				y2=bmu_obs.array[j].dims.xy.y;

				dist=eucl_distance(x1, y1, x2, y2);
				sum_radii=bmu_obs.array[i].dims.diameter/2+bmu_obs.array[j].dims.diameter/2;
				if(dist-sum_radii<0 && dist>0) {
					//double max=bmu_obs.array[i].dims.diameter/2;
					//if(max<bmu_obs.array[i+1].dims.diameter/2) max=bmu_obs.array[i+1].dims.diameter/2;

					overlap=sum_radii-dist;
					alpha = atan(BMU_DIRECTION.y/BMU_DIRECTION.x);
					if(rnd_numbers()>0.5) alpha=alpha+PI/2;
					else alpha=alpha-PI/2;


					new_y=sin(alpha)*overlap;
					new_x=cos(alpha)*overlap;

					/*if(BMU_DIRECTION.x<0 && BMU_DIRECTION.y<0) {
							new_x=new_x*-1;
							new_y=new_y*-1;
						}
						else if(BMU_DIRECTION.x<0 && BMU_DIRECTION.y>0){
							new_x=new_x*-1;
							new_y=new_y*-1;
						}
					*/
					bmu_obs.array[j].dims.xy.x=new_x+bmu_obs.array[j].dims.xy.x;
					bmu_obs.array[j].dims.xy.y=new_y+bmu_obs.array[j].dims.xy.y;

					solved=FALSE;
				}
			}
			iterations_threshold=iterations_threshold+1;
		}

	}

	for(i=0;i<bmu_obs.size;i++){
		add_new_ob_position_message(bmu_obs.array[i].id, bmu_obs.array[i].dims);
	}

	free_celldim(&d);
	free_dim_id_array(&bmu_obs);
	return 0;
}
int oc_push_check(){
	dim_id_array bmu_obs;
	init_dim_id_array(&bmu_obs);

	celldim d;
	init_celldim(&d);

	START_OC_UPDATED_POSITION_MESSAGE_LOOP
		copy_celldim(&oc_updated_position_message->oc_dimension, &d);
		add_dim_id(&bmu_obs,&d,oc_updated_position_message->id);
	FINISH_OC_UPDATED_POSITION_MESSAGE_LOOP

	int solved=FALSE;
	int iterations_threshold=0;
	int i,j;
	double x1,y1,x2,y2;
	double new_x, new_y, alpha, overlap, dist, sum_radii;

	while(solved==FALSE && iterations_threshold<1000000){

		solved=TRUE;
		for(i=0;i<bmu_obs.size;i++){
			for(j=0;j<bmu_obs.size;j++){
				x1=bmu_obs.array[i].dims.xy.x;
				y1=bmu_obs.array[i].dims.xy.y;
				x2=bmu_obs.array[j].dims.xy.x;
				y2=bmu_obs.array[j].dims.xy.y;

				dist=eucl_distance(x1, y1, x2, y2);
				sum_radii=bmu_obs.array[i].dims.diameter/2+bmu_obs.array[j].dims.diameter/2;
				if(dist-sum_radii<0 && dist>0) {
					//double max=bmu_obs.array[i].dims.diameter/2;
					//if(max<bmu_obs.array[i+1].dims.diameter/2) max=bmu_obs.array[i+1].dims.diameter/2;

					overlap=sum_radii-dist;
					alpha = atan(BMU_DIRECTION.y/BMU_DIRECTION.x);
					if(rnd_numbers()>0.5) alpha=alpha+PI/2;
					else alpha=alpha-PI/2;


					new_y=sin(alpha)*overlap;
					new_x=cos(alpha)*overlap;


					bmu_obs.array[j].dims.xy.x=new_x+bmu_obs.array[j].dims.xy.x;
					bmu_obs.array[j].dims.xy.y=new_y+bmu_obs.array[j].dims.xy.y;

					solved=FALSE;
				}
			}
			iterations_threshold=iterations_threshold+1;
		}

	}

	for(i=0;i<bmu_obs.size;i++){
		add_new_oc_position_message(bmu_obs.array[i].id, bmu_obs.array[i].dims);
	}

	free_celldim(&d);
	free_dim_id_array(&bmu_obs);
	return 0;
}

int bmu_update_data(){
	BMU_AGE=BMU_AGE+1;
	//BMU_LENGTH=BMU_LENGTH;
	//BMU_WIDTH=BMU_WIDTH;
	int n_oc=0;
	int n_ob=0;
	START_DEATH_MESSAGE_LOOP
		if(death_message->celltype==OC_TYPE && death_message->bmu_id==BMU_ID){
			n_oc=n_oc+1;
		}
		if(death_message->celltype==OB_TYPE && death_message->bmu_id==BMU_ID){
			n_ob=n_ob+1;
		}
	FINISH_DEATH_MESSAGE_LOOP

	OC_PRESENT=OC_PRESENT-n_oc;
	OB_PRESENT=OB_PRESENT-n_ob;

	Z=Z-OC_PRESENT*OC_RESORB+OB_PRESENT*OB_SYNTH;
	return 0;
}

int signal_position(){
	add_bmu_position_message(BMU_POSITION, BMU_ID);
	return 0;
}



