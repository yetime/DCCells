/*
 * stuff.h
 *
 *  Created on: 09 Dec 2015
 *      Author: yeti
 *
 *  header for stuff functions for sims
 */

#define PI 3.141593
#define DCC_DEBUG 1
#define TRUE 1
#define FALSE 0

#define FUSION_FUSE 0
#define FUSION_DEL 1

int sim_ob_counter;
int sim_oc_counter;
int sim_bmu_counter;

typedef struct item {
	struct item *next;
	int value;
} item_i;


double rnd_numbers();
double rnd_numbers_minmax(int min, int max);
double rnd_numbers_normal(double variance);
double eucl_distance(int x1, int x2, int y1, int y2);

//things related to id's
int get_new_oc_id();
int get_new_ob_id();
int get_new_bmu_id();

//simple list
item_i* add_list_item(item_i *head,int new_i);
int list_has_item(item_i *head,int i);
int free_items(item_i *head);
