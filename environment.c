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

int gen_bmus(){

	if(rnd_numbers()<=BMU_FREQ){
		coordinate bmu_dir;
		init_coordinate(&bmu_dir);
		bmu_dir.x=rnd_numbers_minmax(1,10);
		bmu_dir.y=rnd_numbers_minmax(1,10);
		if(rnd_numbers()<0.5) bmu_dir.x=bmu_dir.x*-1;
		if(rnd_numbers()<0.5) bmu_dir.y=bmu_dir.y*-1;


		coordinate bmu_pos;
		init_coordinate(&bmu_pos);
		bmu_pos.x=rnd_numbers_minmax(1,WORLDSIZE);
		bmu_pos.y=rnd_numbers_minmax(1,WORLDSIZE);

		add_bmu_agent(get_new_bmu_id(),bmu_dir, BMU_AV_SPEED, bmu_pos, 0, 0, 0, 0, 0, 100);
	}

	return 0;
}
