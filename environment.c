/*
 * environment.c
 *
 *  Created on: 17 Dec 2014
 *      Author: yeti
 */


#include "header.h"
#include "environment_agent_header.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

double rnd();

int send_random_number(){
	
	if(RAND_INIT==0){
		srand(time(NULL));
		RAND_INIT=1;
	}
	
	START_RND_NUMBER_REQ_MESSAGE_LOOP
		add_rnd_number_message(rnd_number_req_message->recipient_id, rnd());
	FINISH_RND_NUMBER_REQ_MESSAGE_LOOP
	return 0;
}

int send_new_oc_id(){
	START_OC_ID_REQ_MESSAGE_LOOP
		add_new_oc_id_message(oc_id_req_message->recipient_id, OC_ID_COUNTER++);
	FINISH_OC_ID_REQ_MESSAGE_LOOP
	return 0;
}

int send_new_ob_id(){
	START_OB_ID_REQ_MESSAGE_LOOP
			add_new_ob_id_message(ob_id_req_message->recipient_id, OB_ID_COUNTER++);
	FINISH_OB_ID_REQ_MESSAGE_LOOP
	return 0;
}

double rnd()
{
    return (double) rand()/(double)RAND_MAX;
}
