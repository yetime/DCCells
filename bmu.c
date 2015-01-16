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

int create(){

		if(BMU_AGE<=BMU_LIFESPAN){
		double rnd_ob=rnd_numbers();
		double rnd_oc=rnd_numbers();

		if(rnd_ob<OB_CREATION_FREQ)
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
		}

		if(rnd_oc<OC_CREATION_FREQ){
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
			add_oc_agent(oc_dim,0,1,get_new_oc_id(), 0, BMU_ID, oc_dir);
		}
		}

	return 0;
}

int bmu_die(){
	if(BMU_AGE>BMU_LIFESPAN)
		BMU_SPEED=0;
	return 0;
}


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
		printf("BMUMOVE: x %f y %f\n", new_x, new_y);
		BMU_POSITION.x=BMU_POSITION.x+new_x;
		BMU_POSITION.y=BMU_POSITION.y+new_y;
	return 0;
}

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

	int i;

	for(i=0;i<bmu_ocs.size-1;i++){
		double x1=bmu_ocs.array[i].dims.xy.x;
		double y1=bmu_ocs.array[i].dims.xy.y;
		double x2=bmu_ocs.array[i+1].dims.xy.x;
		double y2=bmu_ocs.array[i+1].dims.xy.y;

		double dist=eucl_distance(x1, y1, x2, y2);

		if(dist<=bmu_ocs.array[i].dims.diameter/2+bmu_ocs.array[i+1].dims.diameter/2) {
			double max=bmu_ocs.array[i].dims.diameter/2;
			if(max<bmu_ocs.array[i+1].dims.diameter/2) max=bmu_ocs.array[i+1].dims.diameter/2;

			double overlap=abs(max-bmu_ocs.array[i].dims.diameter/2-bmu_ocs.array[i+1].dims.diameter/2);
			double old_overlap=cellid_in_array(fusp, bmu_ocs.array[i].id);
			if(old_overlap<0 && (bmu_ocs.array[i].dims.nuclei+bmu_ocs.array[i+1].dims.nuclei)<=OC_MAX_NUCLEI) {
				add_fusion_pair(&fusp, bmu_ocs.array[i].id, &bmu_ocs.array[i].dims, bmu_ocs.array[i+1].id, &bmu_ocs.array[i+1].dims, overlap);
			}
			else if(old_overlap<overlap && (bmu_ocs.array[i].dims.nuclei+bmu_ocs.array[i+1].dims.nuclei)<=OC_MAX_NUCLEI){
					replace_fusion_pair(bmu_ocs.array[i], bmu_ocs.array[i+1], fusp, overlap);
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
	int i;

	while(solved==FALSE && iterations_threshold<100){

		solved=TRUE;
		for(i=0;i<bmu_obs.size-1;i++){
			double x1=bmu_obs.array[i].dims.xy.x;
			double y1=bmu_obs.array[i].dims.xy.y;
			double x2=bmu_obs.array[i+1].dims.xy.x;
			double y2=bmu_obs.array[i+1].dims.xy.y;

			double dist=eucl_distance(x1, y1, x2, y2);
			if(dist<=bmu_obs.array[i].dims.diameter/2+bmu_obs.array[i+1].dims.diameter/2) {
				double max=bmu_obs.array[i].dims.diameter/2;
				if(max<bmu_obs.array[i+1].dims.diameter/2) max=bmu_obs.array[i+1].dims.diameter/2;

				double overlap=abs(max-bmu_obs.array[i].dims.diameter/2-bmu_obs.array[i+1].dims.diameter/2);

				double alpha = atan(BMU_DIRECTION.y/BMU_DIRECTION.x);
				if(rnd_numbers()>0.5) alpha=alpha+PI/2;
				else alpha=alpha-PI/2;

				double new_y=sin(alpha)*overlap;
				double new_x=cos(alpha)*overlap;

				bmu_obs.array[i+1].dims.xy.x=new_x+bmu_obs.array[i+1].dims.xy.x;
				bmu_obs.array[i+1].dims.xy.y=new_y+bmu_obs.array[i+1].dims.xy.y;

				solved=FALSE;
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

int bmu_getolder(){
	BMU_AGE=BMU_AGE+1;
	return 0;
}



