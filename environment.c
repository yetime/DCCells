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
#include "stuff.h"

int initialize(){
	printf("ENV INIT\n");
	srand(time(NULL));

	coordinate pos;
	init_coordinate(&pos);
	pos.x=0;
	pos.y=0;
	celldim dim;
	init_celldim(&dim);
	dim.xy=pos;
	dim.diameter=0;
	add_oc_position_message(dim,-1,-1);
	add_ob_position_message(dim, -1);
	RAND_INIT=1;
	printf("ENV INIT EXIT\n");
	return 0;
}


