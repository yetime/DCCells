/*
 * stuff.c
 *
 *  Created on: 09 Dec 2015
 *      Author: yeti
 *
 *  Helper functions for sims
 */

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "header.h"
#include "stuff.h"

int sim_ob_counter=0;
int sim_oc_counter=0;
int sim_bmu_counter=0;


int get_new_oc_id(){
	sim_oc_counter=sim_oc_counter+1;
	return sim_oc_counter;
}

int get_new_ob_id(){
	sim_ob_counter=sim_ob_counter+1;
	return sim_ob_counter;
}

int get_new_bmu_id(){
	sim_bmu_counter=sim_bmu_counter+1;
	return sim_bmu_counter;
}


double eucl_distance(int x1, int y1,int x2, int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// Uniformly distr. random number
double rnd_numbers(){
	//printf("rnd: %f\n", rand());
	//printf("max: %f\n", RAND_MAX);
	double r=(double) rand()/RAND_MAX;
    return r;
}

// Normal distr. random number - Box-Muller transform (for biased random walk of OC), adjustable via standart deviation
double rnd_numbers_normal(double std_dev){

	double rnd1=rnd_numbers();
	double rnd2=rnd_numbers();

	double rnd_normal=sqrt(std_dev*std_dev*(-2*log(rnd1)))*cos(2*PI*rnd2);
	return rnd_normal;

}

double rnd_numbers_minmax(int min, int max)
{
    int diff = max-min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + min);
}

item_i* add_list_item(item_i *head,int new_i){
	if(head==NULL) return FALSE;
    item_i *new_item = NULL;
    new_item=malloc(sizeof(item_i));

    new_item->value=new_i;
    new_item->next=head;

	return new_item;
}

int list_has_item(item_i *head,int i){
	if (head==NULL) return FALSE;
	item_i *current=head;
	while (current!=NULL){
		if (current->value==i) return TRUE;
		else current=current->next;
	}
	return FALSE;
}

int free_items(item_i *head){
	while(head!=NULL) {
		item_i *del=NULL;
		del=malloc(sizeof(item_i));
		del=head;
		head=head->next;
		free(del);
	}
	return TRUE;
}

