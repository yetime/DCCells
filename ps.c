/*
 * ps.c
 *
 *  Created on: 4 Dec 2014
 *      Author: Christine
 *
 */



#include "header.h"
#include "pointsource_agent_header.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int init(){
	printf("intit\ņ");
	if(ACTIVE==0) ACTIVE=1;
	return 0;
}

int inactive(){
	printf("idle\n");
	return 0;
}

int decay(){
	printf("PS decay\n");
	if(ACTIVE==1){
		double new_conc=DESCRIP.current_conc;
		new_conc=DESCRIP.max_conc*exp(DESCRIP.decay_exp*DESCRIP.lifetime);
		DESCRIP.current_conc=new_conc;
	}
	if(DESCRIP.current_conc<=DESCRIP.base_conc) ACTIVE=0;
	return 0;
}

int signal(){
	printf("PS signal\n");
	if(ACTIVE==1){
		printf("    active\n");
		ps pointsource;
		init_ps(&pointsource);
		copy_ps(&DESCRIP,&pointsource);
		add_pointsource_message(pointsource);
	}
	return 0;
}

int increase_lifetime(){
	printf("PS increase_lifetime\n");
	int lifetime=DESCRIP.lifetime;
	DESCRIP.lifetime=lifetime+1;
	printf("lifetime: %d\n", DESCRIP.lifetime);
	return 0;
}
