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

	START_FUSION_MESSAGE_LOOP
	FINISH_FUSION_MESSAGE_LOOP

	add_fusion_signal_message(0,0,0);
	return 0;
}

int ob_push_check(){
	dim_id_array bmu_obs;
	init_dim_id_array(&bmu_obs);

	START_OB_POSITION_MESSAGE_LOOP
		celldim d;
		init_celldim(&d);
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

	free_dim_id_array(&bmu_obs);
	return 0;
}

int bmu_getolder(){
	BMU_AGE=BMU_AGE+1;
	return 0;
}



