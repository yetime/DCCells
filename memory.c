/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"


void unittest_initialize_oc_start_end()
{
	
	
	//return initialize_oc();
}

void unittest_signal_oc_position_start_1()
{
	
	
	//return signal_oc_position();
}

void unittest_check_fusions_1_2()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_oc_position, &i_oc_position);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'oc_position'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'oc_position' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'oc_position' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return check_fusions();
}

void unittest_fuse_2_3()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_fusion_signal, &i_fusion_signal);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'fusion_signal'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'fusion_signal' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fusion_signal' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return fuse();
}

void unittest_oc_move_3_4()
{
	
	
	//return oc_move();
}

void unittest_oc_get_older_4_5()
{
	
	
	//return oc_get_older();
}

void unittest_oc_die_5_end()
{
	
	
	//return oc_die();
}

void unittest_initialize_ob_start_end()
{
	
	
	//return initialize_ob();
}

void unittest_signal_ob_position_start_1()
{
	
	
	//return signal_ob_position();
}

void unittest_ob_get_older_1_2()
{
	
	
	//return ob_get_older();
}

void unittest_ob_die_2_end()
{
	
	
	//return ob_die();
}

void unittest_create_start_1()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_oc_position, &i_oc_position);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'oc_position'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'oc_position' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'oc_position' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_ob_position, &i_ob_position);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'ob_position'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'ob_position' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ob_position' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return create();
}

void unittest_bmu_die_1_2()
{
	
	
	//return bmu_die();
}

void unittest_calc_fusions_2_3()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_fusion, &i_fusion);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'fusion'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'fusion' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fusion' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return calc_fusions();
}

void unittest_bmu_move_3_end()
{
	
	
	//return bmu_move();
}

void unittest_initialize_start_end()
{
	
	
	//return initialize();
}


void free_messages()
{
	int rc;
	
	    rc = MB_Clear(b_oc_position);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'oc_position' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'oc_position' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'oc_position' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_ob_position);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'ob_position' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'ob_position' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'ob_position' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_fusion);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'fusion' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'fusion' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'fusion' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_fusion_signal);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'fusion_signal' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'fusion_signal' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'fusion_signal' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
}

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
int rc;

	/* Initialise message sync composite params as NULL */
	FLAME_m_oc_position_composite_params = NULL;

	    rc = MB_Create(&b_oc_position, sizeof(m_oc_position));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'oc_position' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_ob_position_composite_params = NULL;

	    rc = MB_Create(&b_ob_position, sizeof(m_ob_position));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'ob_position' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_fusion_composite_params = NULL;

	    rc = MB_Create(&b_fusion, sizeof(m_fusion));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'fusion' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_fusion_signal_composite_params = NULL;

	    rc = MB_Create(&b_fusion_signal, sizeof(m_fusion_signal));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'fusion_signal' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	oc_5_state = init_oc_state();

	oc_4_state = init_oc_state();

	oc_3_state = init_oc_state();

	oc_2_state = init_oc_state();

	oc_1_state = init_oc_state();

	oc_end_state = init_oc_state();

	oc_start_state = init_oc_state();

	ob_2_state = init_ob_state();

	ob_1_state = init_ob_state();

	ob_end_state = init_ob_state();

	ob_start_state = init_ob_state();

	bmu_end_state = init_bmu_state();

	bmu_3_state = init_bmu_state();

	bmu_2_state = init_bmu_state();

	bmu_1_state = init_bmu_state();

	bmu_start_state = init_bmu_state();

	environment_end_state = init_environment_state();

	environment_start_state = init_environment_state();

	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	int rc;

	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
	       default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);

	}
	#endif

	initialise_pointers();
}

FLAME_output * add_FLAME_output(FLAME_output ** outputs)
{
	FLAME_output * current;

	current = (FLAME_output *)malloc(sizeof(FLAME_output));
	CHECK_POINTER(current);
	current->next = *outputs;
	*outputs = current;

	current->type = -1;
	current->format = -1;
	current->location = NULL;
	current->period = -1;
	current->phase = -1;
	current->flag = 0;

	return current;
}

void free_FLAME_outputs(FLAME_output ** outputs)
{
	FLAME_output * current, * next;

	current = *outputs;
	while(current)
	{
		next = current->next;
		free(current->location);
		free(current);
		current = next;
	}
	*outputs = NULL;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;

	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}

	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}

	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_location = NULL;
}

void init_int_static_array(/*@out@*/ int * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(/*@out@*/ float * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(/*@out@*/ double* array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(/*@out@*/ char * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = '\0';
}



void init_coordinate(/*@out@*/ coordinate * temp)
{
	(*temp).x = 0.0;
	(*temp).y = 0.0;

}

void init_coordinate_static_array(/*@out@*/ coordinate * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_coordinate(&array[i]);
}

void free_coordinate(coordinate * temp)
{

}

void free_coordinate_static_array(coordinate * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_coordinate(&array[i]);
}

void copy_coordinate(coordinate * from, coordinate * to)
{
	(*to).x = (*from).x;
	(*to).y = (*from).y;
}

void copy_coordinate_static_array(coordinate * from, coordinate * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_coordinate(&from[i], &to[i]);
	}
}


void init_celldim(/*@out@*/ celldim * temp)
{
	init_coordinate(&(*temp).xy);
	(*temp).diameter = 0.0;

}

void init_celldim_static_array(/*@out@*/ celldim * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_celldim(&array[i]);
}

void free_celldim(celldim * temp)
{
	free_coordinate(&(*temp).xy);

}

void free_celldim_static_array(celldim * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_celldim(&array[i]);
}

void copy_celldim(celldim * from, celldim * to)
{
	copy_coordinate(&(*from).xy, &(*to).xy);
	(*to).diameter = (*from).diameter;
}

void copy_celldim_static_array(celldim * from, celldim * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_celldim(&from[i], &to[i]);
	}
}



xmachine_memory_oc_state * init_oc_state()
{
	xmachine_memory_oc_state * current = (xmachine_memory_oc_state *)malloc(sizeof(xmachine_memory_oc_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_oc * init_oc_agent()
{
	xmachine_memory_oc * current = (xmachine_memory_oc *)malloc(sizeof(xmachine_memory_oc));
	CHECK_POINTER(current);

	init_celldim(&current->oc_dim);
	current->oc_age = 0;
	current->oc_nuclei = 0;
	current->oc_id = 0;
	current->oc_death_prob = 0.0;
	current->oc_mybmu = 0;
	init_coordinate(&current->oc_direction);

	return current;
}

void free_oc_agent(xmachine_memory_oc_holder * tmp, xmachine_memory_oc_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_celldim(&tmp->agent->oc_dim);
	free_coordinate(&tmp->agent->oc_direction);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_oc_agent()
{
	current_xmachine_oc = (xmachine_memory_oc *)malloc(sizeof(xmachine_memory_oc));
	CHECK_POINTER(current);

		init_celldim(&current_xmachine_oc->oc_dim);
		current_xmachine_oc->oc_age = 0;
		current_xmachine_oc->oc_nuclei = 0;
		current_xmachine_oc->oc_id = 0;
		current_xmachine_oc->oc_death_prob = 0.0;
		current_xmachine_oc->oc_mybmu = 0;
		init_coordinate(&current_xmachine_oc->oc_direction);
	
}

void unittest_free_oc_agent()
{
	free_celldim(&current_xmachine_oc->oc_dim);
	free_coordinate(&current_xmachine_oc->oc_direction);
	
	free(current_xmachine_oc);
}

void free_oc_agents()
{
	current_xmachine_oc_holder = oc_5_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_5_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_5_state->count = 0;
	current_xmachine_oc_holder = oc_4_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_4_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_4_state->count = 0;
	current_xmachine_oc_holder = oc_3_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_3_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_3_state->count = 0;
	current_xmachine_oc_holder = oc_2_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_2_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_2_state->count = 0;
	current_xmachine_oc_holder = oc_1_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_1_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_1_state->count = 0;
	current_xmachine_oc_holder = oc_end_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_end_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_end_state->count = 0;
	current_xmachine_oc_holder = oc_start_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_start_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_start_state->count = 0;
}

void free_oc_states()
{
	free(oc_5_state);
	free(oc_4_state);
	free(oc_3_state);
	free(oc_2_state);
	free(oc_1_state);
	free(oc_end_state);
	free(oc_start_state);
}

void transition_oc_agent(xmachine_memory_oc_holder * tmp, xmachine_memory_oc_state * from_state, xmachine_memory_oc_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_oc_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_oc_agent_internal(xmachine_memory_oc * agent, xmachine_memory_oc_state * state)
{
	xmachine_memory_oc_holder * current = (xmachine_memory_oc_holder *)malloc(sizeof(xmachine_memory_oc_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_oc_agent(celldim * oc_dim, int oc_age, int oc_nuclei, int oc_id, double oc_death_prob, int oc_mybmu, coordinate * oc_direction)
 * \brief Add oc X-machine to the current being used X-machine list.
 * \param oc_dim Variable for the X-machine memory.
 * \param oc_age Variable for the X-machine memory.
 * \param oc_nuclei Variable for the X-machine memory.
 * \param oc_id Variable for the X-machine memory.
 * \param oc_death_prob Variable for the X-machine memory.
 * \param oc_mybmu Variable for the X-machine memory.
 * \param oc_direction Variable for the X-machine memory.
 */
void add_oc_agent(celldim oc_dim, int oc_age, int oc_nuclei, int oc_id, double oc_death_prob, int oc_mybmu, coordinate oc_direction)
{
	xmachine_memory_oc * current;

	current = init_oc_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_oc_next_state = oc_start_state;
	add_oc_agent_internal(current, current_xmachine_oc_next_state);

	copy_celldim(&oc_dim, &current->oc_dim);
	current->oc_age = oc_age;
	current->oc_nuclei = oc_nuclei;
	current->oc_id = oc_id;
	current->oc_death_prob = oc_death_prob;
	current->oc_mybmu = oc_mybmu;
	copy_coordinate(&oc_direction, &current->oc_direction);
}

xmachine_memory_ob_state * init_ob_state()
{
	xmachine_memory_ob_state * current = (xmachine_memory_ob_state *)malloc(sizeof(xmachine_memory_ob_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_ob * init_ob_agent()
{
	xmachine_memory_ob * current = (xmachine_memory_ob *)malloc(sizeof(xmachine_memory_ob));
	CHECK_POINTER(current);

	init_celldim(&current->ob_dim);
	current->ob_age = 0;
	current->ob_id = 0;
	current->ob_death_prob = 0.0;
	current->ob_mybmu = 0;

	return current;
}

void free_ob_agent(xmachine_memory_ob_holder * tmp, xmachine_memory_ob_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_celldim(&tmp->agent->ob_dim);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_ob_agent()
{
	current_xmachine_ob = (xmachine_memory_ob *)malloc(sizeof(xmachine_memory_ob));
	CHECK_POINTER(current);

		init_celldim(&current_xmachine_ob->ob_dim);
		current_xmachine_ob->ob_age = 0;
		current_xmachine_ob->ob_id = 0;
		current_xmachine_ob->ob_death_prob = 0.0;
		current_xmachine_ob->ob_mybmu = 0;
	
}

void unittest_free_ob_agent()
{
	free_celldim(&current_xmachine_ob->ob_dim);
	
	free(current_xmachine_ob);
}

void free_ob_agents()
{
	current_xmachine_ob_holder = ob_2_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		free_ob_agent(current_xmachine_ob_holder, ob_2_state);
		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	ob_2_state->count = 0;
	current_xmachine_ob_holder = ob_1_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		free_ob_agent(current_xmachine_ob_holder, ob_1_state);
		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	ob_1_state->count = 0;
	current_xmachine_ob_holder = ob_end_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		free_ob_agent(current_xmachine_ob_holder, ob_end_state);
		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	ob_end_state->count = 0;
	current_xmachine_ob_holder = ob_start_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		free_ob_agent(current_xmachine_ob_holder, ob_start_state);
		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	ob_start_state->count = 0;
}

void free_ob_states()
{
	free(ob_2_state);
	free(ob_1_state);
	free(ob_end_state);
	free(ob_start_state);
}

void transition_ob_agent(xmachine_memory_ob_holder * tmp, xmachine_memory_ob_state * from_state, xmachine_memory_ob_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_ob_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_ob_agent_internal(xmachine_memory_ob * agent, xmachine_memory_ob_state * state)
{
	xmachine_memory_ob_holder * current = (xmachine_memory_ob_holder *)malloc(sizeof(xmachine_memory_ob_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_ob_agent(celldim * ob_dim, int ob_age, int ob_id, double ob_death_prob, int ob_mybmu)
 * \brief Add ob X-machine to the current being used X-machine list.
 * \param ob_dim Variable for the X-machine memory.
 * \param ob_age Variable for the X-machine memory.
 * \param ob_id Variable for the X-machine memory.
 * \param ob_death_prob Variable for the X-machine memory.
 * \param ob_mybmu Variable for the X-machine memory.
 */
void add_ob_agent(celldim ob_dim, int ob_age, int ob_id, double ob_death_prob, int ob_mybmu)
{
	xmachine_memory_ob * current;

	current = init_ob_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_ob_next_state = ob_start_state;
	add_ob_agent_internal(current, current_xmachine_ob_next_state);

	copy_celldim(&ob_dim, &current->ob_dim);
	current->ob_age = ob_age;
	current->ob_id = ob_id;
	current->ob_death_prob = ob_death_prob;
	current->ob_mybmu = ob_mybmu;
}

xmachine_memory_bmu_state * init_bmu_state()
{
	xmachine_memory_bmu_state * current = (xmachine_memory_bmu_state *)malloc(sizeof(xmachine_memory_bmu_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_bmu * init_bmu_agent()
{
	xmachine_memory_bmu * current = (xmachine_memory_bmu *)malloc(sizeof(xmachine_memory_bmu));
	CHECK_POINTER(current);

	current->bmu_id = 0;
	init_coordinate(&current->bmu_direction);
	current->bmu_speed = 0.0;
	init_coordinate(&current->bmu_position);
	current->bmu_length = 0;

	return current;
}

void free_bmu_agent(xmachine_memory_bmu_holder * tmp, xmachine_memory_bmu_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_coordinate(&tmp->agent->bmu_direction);
	free_coordinate(&tmp->agent->bmu_position);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_bmu_agent()
{
	current_xmachine_bmu = (xmachine_memory_bmu *)malloc(sizeof(xmachine_memory_bmu));
	CHECK_POINTER(current);

		current_xmachine_bmu->bmu_id = 0;
		init_coordinate(&current_xmachine_bmu->bmu_direction);
		current_xmachine_bmu->bmu_speed = 0.0;
		init_coordinate(&current_xmachine_bmu->bmu_position);
		current_xmachine_bmu->bmu_length = 0;
	
}

void unittest_free_bmu_agent()
{
	free_coordinate(&current_xmachine_bmu->bmu_direction);
	free_coordinate(&current_xmachine_bmu->bmu_position);
	
	free(current_xmachine_bmu);
}

void free_bmu_agents()
{
	current_xmachine_bmu_holder = bmu_end_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		free_bmu_agent(current_xmachine_bmu_holder, bmu_end_state);
		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	bmu_end_state->count = 0;
	current_xmachine_bmu_holder = bmu_3_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		free_bmu_agent(current_xmachine_bmu_holder, bmu_3_state);
		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	bmu_3_state->count = 0;
	current_xmachine_bmu_holder = bmu_2_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		free_bmu_agent(current_xmachine_bmu_holder, bmu_2_state);
		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	bmu_2_state->count = 0;
	current_xmachine_bmu_holder = bmu_1_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		free_bmu_agent(current_xmachine_bmu_holder, bmu_1_state);
		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	bmu_1_state->count = 0;
	current_xmachine_bmu_holder = bmu_start_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		free_bmu_agent(current_xmachine_bmu_holder, bmu_start_state);
		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	bmu_start_state->count = 0;
}

void free_bmu_states()
{
	free(bmu_end_state);
	free(bmu_3_state);
	free(bmu_2_state);
	free(bmu_1_state);
	free(bmu_start_state);
}

void transition_bmu_agent(xmachine_memory_bmu_holder * tmp, xmachine_memory_bmu_state * from_state, xmachine_memory_bmu_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_bmu_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_bmu_agent_internal(xmachine_memory_bmu * agent, xmachine_memory_bmu_state * state)
{
	xmachine_memory_bmu_holder * current = (xmachine_memory_bmu_holder *)malloc(sizeof(xmachine_memory_bmu_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_bmu_agent(int bmu_id, coordinate * bmu_direction, double bmu_speed, coordinate * bmu_position, int bmu_length)
 * \brief Add bmu X-machine to the current being used X-machine list.
 * \param bmu_id Variable for the X-machine memory.
 * \param bmu_direction Variable for the X-machine memory.
 * \param bmu_speed Variable for the X-machine memory.
 * \param bmu_position Variable for the X-machine memory.
 * \param bmu_length Variable for the X-machine memory.
 */
void add_bmu_agent(int bmu_id, coordinate bmu_direction, double bmu_speed, coordinate bmu_position, int bmu_length)
{
	xmachine_memory_bmu * current;

	current = init_bmu_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_bmu_next_state = bmu_start_state;
	add_bmu_agent_internal(current, current_xmachine_bmu_next_state);

	current->bmu_id = bmu_id;
	copy_coordinate(&bmu_direction, &current->bmu_direction);
	current->bmu_speed = bmu_speed;
	copy_coordinate(&bmu_position, &current->bmu_position);
	current->bmu_length = bmu_length;
}

xmachine_memory_environment_state * init_environment_state()
{
	xmachine_memory_environment_state * current = (xmachine_memory_environment_state *)malloc(sizeof(xmachine_memory_environment_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_environment * init_environment_agent()
{
	xmachine_memory_environment * current = (xmachine_memory_environment *)malloc(sizeof(xmachine_memory_environment));
	CHECK_POINTER(current);

	current->rand_init = 0;

	return current;
}

void free_environment_agent(xmachine_memory_environment_holder * tmp, xmachine_memory_environment_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_environment_agent()
{
	current_xmachine_environment = (xmachine_memory_environment *)malloc(sizeof(xmachine_memory_environment));
	CHECK_POINTER(current);

		current_xmachine_environment->rand_init = 0;
	
}

void unittest_free_environment_agent()
{
	
	free(current_xmachine_environment);
}

void free_environment_agents()
{
	current_xmachine_environment_holder = environment_end_state->agents;
	while(current_xmachine_environment_holder)
	{
		temp_xmachine_environment_holder = current_xmachine_environment_holder->next;
		free_environment_agent(current_xmachine_environment_holder, environment_end_state);
		current_xmachine_environment_holder = temp_xmachine_environment_holder;
	}
	environment_end_state->count = 0;
	current_xmachine_environment_holder = environment_start_state->agents;
	while(current_xmachine_environment_holder)
	{
		temp_xmachine_environment_holder = current_xmachine_environment_holder->next;
		free_environment_agent(current_xmachine_environment_holder, environment_start_state);
		current_xmachine_environment_holder = temp_xmachine_environment_holder;
	}
	environment_start_state->count = 0;
}

void free_environment_states()
{
	free(environment_end_state);
	free(environment_start_state);
}

void transition_environment_agent(xmachine_memory_environment_holder * tmp, xmachine_memory_environment_state * from_state, xmachine_memory_environment_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_environment_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_environment_agent_internal(xmachine_memory_environment * agent, xmachine_memory_environment_state * state)
{
	xmachine_memory_environment_holder * current = (xmachine_memory_environment_holder *)malloc(sizeof(xmachine_memory_environment_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_environment_agent(int rand_init)
 * \brief Add environment X-machine to the current being used X-machine list.
 * \param rand_init Variable for the X-machine memory.
 */
void add_environment_agent(int rand_init)
{
	xmachine_memory_environment * current;

	current = init_environment_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_environment_next_state = environment_start_state;
	add_environment_agent_internal(current, current_xmachine_environment_next_state);

	current->rand_init = rand_init;
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_oc_agents();
	free_ob_agents();
	free_bmu_agents();
	free_environment_agents();
	
}


/** \fn celldim get_oc_dim()
 * \brief Get oc_dim memory variable from current X-machine.
 * \return Value for variable.
 */
celldim * get_oc_dim()
{
	if(current_xmachine->xmachine_oc) return &(*current_xmachine->xmachine_oc).oc_dim;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_oc_age(int oc_age)
 * \brief Set oc_age memory variable for current X-machine.
 * \param oc_age New value for variable.
 */
void set_oc_age(int oc_age)
{
	if(current_xmachine->xmachine_oc) (*current_xmachine->xmachine_oc).oc_age = oc_age;
}

/** \fn int get_oc_age()
 * \brief Get oc_age memory variable from current X-machine.
 * \return Value for variable.
 */
int get_oc_age()
{
	if(current_xmachine->xmachine_oc) return (*current_xmachine->xmachine_oc).oc_age;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_oc_nuclei(int oc_nuclei)
 * \brief Set oc_nuclei memory variable for current X-machine.
 * \param oc_nuclei New value for variable.
 */
void set_oc_nuclei(int oc_nuclei)
{
	if(current_xmachine->xmachine_oc) (*current_xmachine->xmachine_oc).oc_nuclei = oc_nuclei;
}

/** \fn int get_oc_nuclei()
 * \brief Get oc_nuclei memory variable from current X-machine.
 * \return Value for variable.
 */
int get_oc_nuclei()
{
	if(current_xmachine->xmachine_oc) return (*current_xmachine->xmachine_oc).oc_nuclei;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_oc_id(int oc_id)
 * \brief Set oc_id memory variable for current X-machine.
 * \param oc_id New value for variable.
 */
void set_oc_id(int oc_id)
{
	if(current_xmachine->xmachine_oc) (*current_xmachine->xmachine_oc).oc_id = oc_id;
}

/** \fn int get_oc_id()
 * \brief Get oc_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_oc_id()
{
	if(current_xmachine->xmachine_oc) return (*current_xmachine->xmachine_oc).oc_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_oc_death_prob(double oc_death_prob)
 * \brief Set oc_death_prob memory variable for current X-machine.
 * \param oc_death_prob New value for variable.
 */
void set_oc_death_prob(double oc_death_prob)
{
	if(current_xmachine->xmachine_oc) (*current_xmachine->xmachine_oc).oc_death_prob = oc_death_prob;
}

/** \fn double get_oc_death_prob()
 * \brief Get oc_death_prob memory variable from current X-machine.
 * \return Value for variable.
 */
double get_oc_death_prob()
{
	if(current_xmachine->xmachine_oc) return (*current_xmachine->xmachine_oc).oc_death_prob;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_oc_mybmu(int oc_mybmu)
 * \brief Set oc_mybmu memory variable for current X-machine.
 * \param oc_mybmu New value for variable.
 */
void set_oc_mybmu(int oc_mybmu)
{
	if(current_xmachine->xmachine_oc) (*current_xmachine->xmachine_oc).oc_mybmu = oc_mybmu;
}

/** \fn int get_oc_mybmu()
 * \brief Get oc_mybmu memory variable from current X-machine.
 * \return Value for variable.
 */
int get_oc_mybmu()
{
	if(current_xmachine->xmachine_oc) return (*current_xmachine->xmachine_oc).oc_mybmu;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn coordinate get_oc_direction()
 * \brief Get oc_direction memory variable from current X-machine.
 * \return Value for variable.
 */
coordinate * get_oc_direction()
{
	if(current_xmachine->xmachine_oc) return &(*current_xmachine->xmachine_oc).oc_direction;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn celldim get_ob_dim()
 * \brief Get ob_dim memory variable from current X-machine.
 * \return Value for variable.
 */
celldim * get_ob_dim()
{
	if(current_xmachine->xmachine_ob) return &(*current_xmachine->xmachine_ob).ob_dim;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_ob_age(int ob_age)
 * \brief Set ob_age memory variable for current X-machine.
 * \param ob_age New value for variable.
 */
void set_ob_age(int ob_age)
{
	if(current_xmachine->xmachine_ob) (*current_xmachine->xmachine_ob).ob_age = ob_age;
}

/** \fn int get_ob_age()
 * \brief Get ob_age memory variable from current X-machine.
 * \return Value for variable.
 */
int get_ob_age()
{
	if(current_xmachine->xmachine_ob) return (*current_xmachine->xmachine_ob).ob_age;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_ob_id(int ob_id)
 * \brief Set ob_id memory variable for current X-machine.
 * \param ob_id New value for variable.
 */
void set_ob_id(int ob_id)
{
	if(current_xmachine->xmachine_ob) (*current_xmachine->xmachine_ob).ob_id = ob_id;
}

/** \fn int get_ob_id()
 * \brief Get ob_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_ob_id()
{
	if(current_xmachine->xmachine_ob) return (*current_xmachine->xmachine_ob).ob_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_ob_death_prob(double ob_death_prob)
 * \brief Set ob_death_prob memory variable for current X-machine.
 * \param ob_death_prob New value for variable.
 */
void set_ob_death_prob(double ob_death_prob)
{
	if(current_xmachine->xmachine_ob) (*current_xmachine->xmachine_ob).ob_death_prob = ob_death_prob;
}

/** \fn double get_ob_death_prob()
 * \brief Get ob_death_prob memory variable from current X-machine.
 * \return Value for variable.
 */
double get_ob_death_prob()
{
	if(current_xmachine->xmachine_ob) return (*current_xmachine->xmachine_ob).ob_death_prob;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_ob_mybmu(int ob_mybmu)
 * \brief Set ob_mybmu memory variable for current X-machine.
 * \param ob_mybmu New value for variable.
 */
void set_ob_mybmu(int ob_mybmu)
{
	if(current_xmachine->xmachine_ob) (*current_xmachine->xmachine_ob).ob_mybmu = ob_mybmu;
}

/** \fn int get_ob_mybmu()
 * \brief Get ob_mybmu memory variable from current X-machine.
 * \return Value for variable.
 */
int get_ob_mybmu()
{
	if(current_xmachine->xmachine_ob) return (*current_xmachine->xmachine_ob).ob_mybmu;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bmu_id(int bmu_id)
 * \brief Set bmu_id memory variable for current X-machine.
 * \param bmu_id New value for variable.
 */
void set_bmu_id(int bmu_id)
{
	if(current_xmachine->xmachine_bmu) (*current_xmachine->xmachine_bmu).bmu_id = bmu_id;
}

/** \fn int get_bmu_id()
 * \brief Get bmu_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bmu_id()
{
	if(current_xmachine->xmachine_bmu) return (*current_xmachine->xmachine_bmu).bmu_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn coordinate get_bmu_direction()
 * \brief Get bmu_direction memory variable from current X-machine.
 * \return Value for variable.
 */
coordinate * get_bmu_direction()
{
	if(current_xmachine->xmachine_bmu) return &(*current_xmachine->xmachine_bmu).bmu_direction;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_bmu_speed(double bmu_speed)
 * \brief Set bmu_speed memory variable for current X-machine.
 * \param bmu_speed New value for variable.
 */
void set_bmu_speed(double bmu_speed)
{
	if(current_xmachine->xmachine_bmu) (*current_xmachine->xmachine_bmu).bmu_speed = bmu_speed;
}

/** \fn double get_bmu_speed()
 * \brief Get bmu_speed memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bmu_speed()
{
	if(current_xmachine->xmachine_bmu) return (*current_xmachine->xmachine_bmu).bmu_speed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn coordinate get_bmu_position()
 * \brief Get bmu_position memory variable from current X-machine.
 * \return Value for variable.
 */
coordinate * get_bmu_position()
{
	if(current_xmachine->xmachine_bmu) return &(*current_xmachine->xmachine_bmu).bmu_position;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_bmu_length(int bmu_length)
 * \brief Set bmu_length memory variable for current X-machine.
 * \param bmu_length New value for variable.
 */
void set_bmu_length(int bmu_length)
{
	if(current_xmachine->xmachine_bmu) (*current_xmachine->xmachine_bmu).bmu_length = bmu_length;
}

/** \fn int get_bmu_length()
 * \brief Get bmu_length memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bmu_length()
{
	if(current_xmachine->xmachine_bmu) return (*current_xmachine->xmachine_bmu).bmu_length;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_rand_init(int rand_init)
 * \brief Set rand_init memory variable for current X-machine.
 * \param rand_init New value for variable.
 */
void set_rand_init(int rand_init)
{
	if(current_xmachine->xmachine_environment) (*current_xmachine->xmachine_environment).rand_init = rand_init;
}

/** \fn int get_rand_init()
 * \brief Get rand_init memory variable from current X-machine.
 * \return Value for variable.
 */
int get_rand_init()
{
	if(current_xmachine->xmachine_environment) return (*current_xmachine->xmachine_environment).rand_init;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->;*/
    /*if (current_xmachine->xmachine_bmu) value = current_xmachine->xmachine_bmu->;*/
    /*if (current_xmachine->xmachine_environment) value = current_xmachine->xmachine_environment->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->;*/
    /*if (current_xmachine->xmachine_bmu) value = current_xmachine->xmachine_bmu->;*/
    /*if (current_xmachine->xmachine_environment) value = current_xmachine->xmachine_environment->;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->0.0;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->0.0;*/
    /*if (current_xmachine->xmachine_bmu) value = current_xmachine->xmachine_bmu->0.0;*/
    /*if (current_xmachine->xmachine_environment) value = current_xmachine->xmachine_environment->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->0.0;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->0.0;*/
    /*if (current_xmachine->xmachine_bmu) value = current_xmachine->xmachine_bmu->0.0;*/
    /*if (current_xmachine->xmachine_environment) value = current_xmachine->xmachine_environment->0.0;*/

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}

/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;

	while(current)
	{
		tmp = current;
		current = current->next;
	}

	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}

	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->oc_position_messages = NULL;
	current->ob_position_messages = NULL;
	current->fusion_messages = NULL;
	current->fusion_signal_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];

	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free output list */
	free_FLAME_outputs(&FLAME_outputs);
	/* Free agent states */
	free_oc_states();
	free_ob_states();
	free_bmu_states();
	free_environment_states();


	/* Free index maps */


	/* Free message boards */

	rc = MB_Delete(&b_oc_position);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'oc_position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'oc_position' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'oc_position' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_ob_position);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'ob_position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ob_position' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ob_position' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_fusion);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'fusion' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fusion' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fusion' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_fusion_signal);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'fusion_signal' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fusion_signal' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fusion_signal' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif



	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<!-- <totaltime> unit: seconds -->\n", file);
	fputs("<totaltime>", file);
	sprintf(data, "%.3f", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);


	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");

		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
/*	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_oc != NULL)
		{
			x_xmachine = current_xmachine->xmachine_oc->0.0;
			y_xmachine = current_xmachine->xmachine_oc->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_ob != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ob->0.0;
			y_xmachine = current_xmachine->xmachine_ob->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_bmu != NULL)
		{
			x_xmachine = current_xmachine->xmachine_bmu->0.0;
			y_xmachine = current_xmachine->xmachine_bmu->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_environment != NULL)
		{
			x_xmachine = current_xmachine->xmachine_environment->0.0;
			y_xmachine = current_xmachine->xmachine_environment->0.0;
			z_xmachine = 0.0;
		}

		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    // Remove agent
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    // Add agent
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;

			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}*/
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;

	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++)
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j);
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;

	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;

	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}

/* Functions for the coordinate datatype */
/** \fn coordinate_array * init_coordinate_array()
 * \brief Allocate memory for a dynamic coordinate array.
 * \return coordinate_array Pointer to the new dynamic coordinate array.
 */
void init_coordinate_array(coordinate_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (coordinate *)malloc(ARRAY_BLOCK_SIZE * sizeof(coordinate));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_coordinate_array(coordinate_array* array)
* \brief Reset the coordinate array to hold nothing.
* \param array Pointer to the dynamic coordinate array.
*/
void reset_coordinate_array(coordinate_array * array)
{
	(*array).size = 0;
}

/** \fn void free_coordinate_array(coordinate_array * array)
* \brief Free the memory of a dynamic coordinate array.
* \param array Pointer to the dynamic coordinate array.
*/
void free_coordinate_array(coordinate_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_coordinate(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_coordinate_array(coordinate_array * from, coordinate_array * to)
{
	int i;

	//to = init_coordinate_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_coordinate(to, (*from).array[i].x, (*from).array[i].y);
	}
}

/** \fn void add_coordinate(coordinate_array * array, double x, double y)
* \brief Add an coordinate to the dynamic coordinate array.
* \param array Pointer to the dynamic coordinate array.
* \param new_int The coordinate to add
*/
void add_coordinate(coordinate_array * array,  double x,  double y)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (coordinate *)realloc((*array).array, ((*array).total_size * sizeof(coordinate)));
	}
	init_coordinate(&(*array).array[(*array).size]);
	(*array).array[(*array).size].x = x;
	(*array).array[(*array).size].y = y;

	(*array).size++;
}

/** \fn void remove_coordinate(coordinate_array * array, int index)
 * \brief Remove an coordinate from a dynamic coordinate array.
 * \param array Pointer to the dynamic coordinate array.
 * \param index The index of the coordinate to remove.
 */
void remove_coordinate(coordinate_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_coordinate(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_coordinate(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the celldim datatype */
/** \fn celldim_array * init_celldim_array()
 * \brief Allocate memory for a dynamic celldim array.
 * \return celldim_array Pointer to the new dynamic celldim array.
 */
void init_celldim_array(celldim_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (celldim *)malloc(ARRAY_BLOCK_SIZE * sizeof(celldim));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_celldim_array(celldim_array* array)
* \brief Reset the celldim array to hold nothing.
* \param array Pointer to the dynamic celldim array.
*/
void reset_celldim_array(celldim_array * array)
{
	(*array).size = 0;
}

/** \fn void free_celldim_array(celldim_array * array)
* \brief Free the memory of a dynamic celldim array.
* \param array Pointer to the dynamic celldim array.
*/
void free_celldim_array(celldim_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_celldim(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_celldim_array(celldim_array * from, celldim_array * to)
{
	int i;

	//to = init_celldim_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_celldim(to, &(*from).array[i].xy, (*from).array[i].diameter);
	}
}

/** \fn void add_celldim(celldim_array * array, coordinate * xy, double diameter)
* \brief Add an celldim to the dynamic celldim array.
* \param array Pointer to the dynamic celldim array.
* \param new_int The celldim to add
*/
void add_celldim(celldim_array * array, /*@out@*/ coordinate * xy,  double diameter)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (celldim *)realloc((*array).array, ((*array).total_size * sizeof(celldim)));
	}
	init_celldim(&(*array).array[(*array).size]);
	copy_coordinate(xy, &(*array).array[(*array).size].xy);
	(*array).array[(*array).size].diameter = diameter;

	(*array).size++;
}

/** \fn void remove_celldim(celldim_array * array, int index)
 * \brief Remove an celldim from a dynamic celldim array.
 * \param array Pointer to the dynamic celldim array.
 * \param index The index of the celldim to remove.
 */
void remove_celldim(celldim_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_celldim(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_celldim(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}

int FLAME_get_environment_variable_worldsize()
{
	return FLAME_environment_variable_worldsize;
}
int FLAME_get_environment_variable_oc_lifespan()
{
	return FLAME_environment_variable_oc_lifespan;
}
int FLAME_get_environment_variable_ob_lifespan()
{
	return FLAME_environment_variable_ob_lifespan;
}
int FLAME_get_environment_variable_bmu_lifespan()
{
	return FLAME_environment_variable_bmu_lifespan;
}
double FLAME_get_environment_variable_oc_creation_freq()
{
	return FLAME_environment_variable_oc_creation_freq;
}
double FLAME_get_environment_variable_ob_creation_freq()
{
	return FLAME_environment_variable_ob_creation_freq;
}
int FLAME_get_environment_variable_oc_diameter()
{
	return FLAME_environment_variable_oc_diameter;
}
int FLAME_get_environment_variable_ob_diameter()
{
	return FLAME_environment_variable_ob_diameter;
}
int FLAME_get_environment_variable_oc_type()
{
	return FLAME_environment_variable_oc_type;
}
int FLAME_get_environment_variable_ob_type()
{
	return FLAME_environment_variable_ob_type;
}
int FLAME_get_environment_variable_bmu_type()
{
	return FLAME_environment_variable_bmu_type;
}
double FLAME_get_environment_variable_oc_speed()
{
	return FLAME_environment_variable_oc_speed;
}
double FLAME_get_environment_variable_oc_displ_stdev()
{
	return FLAME_environment_variable_oc_displ_stdev;
}


