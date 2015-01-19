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

int initialize() {
	srand(time(NULL));

	RAND_INIT = 1;
	return 0;
}

