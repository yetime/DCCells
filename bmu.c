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

int create(){

	double rnds[2]={0,0};

	int count=0;

	START_RND_NUMBER_MESSAGE_LOOP
		if(rnd_number_message->recipient_id==BMU_ID){
			if(count<=1){
				rnds[count]=rnd_number_message->rnd_number;
				count++;
			}
		}
	FINISH_RND_NUMBER_MESSAGE_LOOP

	START_NEW_OB_ID_MESSAGE_LOOP
		if(OB_CREATION_FREQ<=rnds[0]) ;
	FINISH_NEW_OB_ID_MESSAGE_LOOP

	START_NEW_OC_ID_MESSAGE_LOOP
	if(OC_CREATION_FREQ<=rnds[1])
			coordinate pos;
			init_coordinate(&pos);
			copy_coordinate(&POSITION,&pos);
			celldim dim;
			init_celldim(&dim);
			dim.xy=pos;
			dim.diameter=20;
			add_oc_agent(dim,0,1,new_oc_id_message->new_id);
	FINISH_NEW_OC_ID_MESSAGE_LOOP
	return 0;
}

int bmu_die(){
	return 0;
}

int bmu_move(){
   return 0;
}

int request_numbers(){
	add_oc_id_req_message(BMU_ID);
	add_ob_id_req_message(BMU_ID);
	add_rnd_number_req_message(BMU_ID);
	add_rnd_number_req_message(BMU_ID);
	return 0;
}
