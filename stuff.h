/*
 * stuff.h
 *
 *  Created on: 09 Dec 2015
 *      Author: yeti
 *
 *  header for stuff functions for sims
 */

#define PI 3.141593

int sim_ob_counter;
int sim_oc_counter;
int sim_bmu_counter;


double rnd_numbers();
double rnd_numbers_normal(double variance);
double eucl_distance(int x1, int x2, int y1, int y2);
int get_new_oc_id();
int get_new_ob_id();
int get_new_bmu_id();
