/*
 * ob.c
 *
 *  Created on: 2 Dec 2014
 *      Author: Christine
 *
 */

#include "header.h"
#include "ob_agent_header.h"
#include "stuff.h"


int initialize_ob(){
	OB_AGE=1;
	return 0;
}

int signal_ob_position(){
	if(OB_AGE!=0) {
		add_ob_position_message(OB_DIM,OB_ID);
	}

	return 0;
}


int ob_move(){
	START_NEW_OB_POSITION_MESSAGE_LOOP
		if(new_ob_position_message->push_id==OB_ID){
			OB_DIM.xy.x=new_ob_position_message->dims.xy.x;
			OB_DIM.xy.y=new_ob_position_message->dims.xy.y;
		}
	FINISH_NEW_OB_POSITION_MESSAGE_LOOP

	return 0;
}


/*
 * Age calculations in minutes...
 */
int ob_get_older(){
	//int min=OB_LIFESPAN-2*1440;
	//int max=OB_LIFESPAN+2*1440; //2 days
	//if(min<0) min=0;

	//if(OB_AGE>=min && OB_AGE<=max){
	//	OB_DEATH_PROB=OB_DEATH_PROB+1/1440;

	//}
	//OB_AGE=OB_AGE+1;

	if(OB_AGE>OB_LIFESPAN) return 1;
	return 0;
}

int ob_die(){
	double rndnr=rnd_numbers();

	if(OB_AGE>OB_LIFESPAN){
			return 1;
		}

	if(rndnr<OB_DEATH_PROB) {
		return 1;
	}
	return 0;
}
