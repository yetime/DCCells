/*
 * dcc.c
 *
 *  Created on: 2 Dec 2014
 *      Author: Christine
 *
 */



#include "header.h"
#include "dcc_agent_header.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

enum celltypes {OC=1, OB=2, DCC=3, OTHER=4};

int respond(){
	START_POSITION_MESSAGE_LOOP
		printf("mylength: %d", GEO.length);
	FINISH_POSITION_MESSAGE_LOOP
	DORMANT=0;
	return 0;
}

int divide(){
	START_POSITION_MESSAGE_LOOP

		FINISH_POSITION_MESSAGE_LOOP
	return 0;
}

