/*
 * ob.c
 *
 *  Created on: 2 Dec 2014
 *      Author: Christine
 *
 */



#include "header.h"
#include "ob_agent_header.h"

int signal_ob_position(){
	add_position_message(GEO,2);
	return 0;
}
