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
		coordinate ob_pos;
		init_coordinate(&ob_pos);
		ob_pos.x=BMU_POSITION.x;
		ob_pos.y=BMU_POSITION.y;
		celldim ob_dim;
		init_celldim(&ob_dim);
		ob_dim.xy=ob_pos;
		ob_dim.diameter=OB_DIAMETER;
		add_ob_agent(ob_dim,0,get_new_ob_id(),0, BMU_ID);

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

	return 0;
}

int bmu_die(){
	return 0;
}

int bmu_move(){
	return 0;
}

int calc_fusions(){
	if(DCC_DEBUG==1) printf("CALC_FUSIONS\n");
	START_FUSION_MESSAGE_LOOP
	FINISH_FUSION_MESSAGE_LOOP

	add_fusion_signal_message(0,0,0);
	return 0;
}



