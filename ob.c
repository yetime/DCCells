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
	printf("OB INIT\n");
	OB_AGE=1;
	printf("OB INIT EXIT\n");
	return 0;
}

int signal_ob_position(){
	printf("OB POSTITION\n");
	if(OB_AGE!=0) {
		add_ob_position_message(OB_DIM,OB_ID);
	}
	printf("OB POSTITION EXIT\n");
	return 0;
}

/*
 * Age calculations in minutes...
 */
int ob_get_older(){
	printf("OB OLDER\n");
	int min=OB_LIFESPAN-2*1440;
	int max=OB_LIFESPAN+2*1440; //2 days
	if(min<0) min=0;

	if(OB_AGE>=min && OB_AGE<=max){
		OB_DEATH_PROB=OB_DEATH_PROB+1/1440;

	}
	OB_AGE=OB_AGE+1;
	printf("OB OLDER EXIT\n");
	return 0;
}

int ob_die(){
	printf("OB DIE\n");
	double rndnr=rnd_numbers();

	if(OB_AGE>OB_LIFESPAN){
			return 1;
		}

	if(rndnr<OB_DEATH_PROB) {
		return 1;
	}
	printf("OB DIE EXIT\n");
	return 0;
}
