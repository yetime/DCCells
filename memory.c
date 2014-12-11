/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"


void unittest_respond_start_end()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_position, &i_position);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'position'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'position' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'position' board is locked\n");
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
	
	//return respond();
}

void unittest_divide_start_end()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_position, &i_position);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'position'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'position' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'position' board is locked\n");
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
	
	//return divide();
}

void unittest_signal_ob_position_start_moving()
{
	
	
	//return signal_ob_position();
}

void unittest_move_moving_end()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_pointsource, &i_pointsource);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'pointsource'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'pointsource' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pointsource' board is locked\n");
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
	
	//return move();
}

void unittest_signal_oc_position_signal_end()
{
	
	
	//return signal_oc_position();
}

void unittest_move_start_signal()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_pointsource, &i_pointsource);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'pointsource'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'pointsource' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pointsource' board is locked\n");
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
	
	//return move();
}

void unittest_init_start_signal()
{
	
	
	//return init();
}

void unittest_decay_start_signal()
{
	
	
	//return decay();
}

void unittest_inactive_start_end()
{
	
	
	//return inactive();
}

void unittest_signal_signal_increase_lifetime()
{
	
	
	//return signal();
}

void unittest_increase_lifetime_increase_lifetime_end()
{
	
	
	//return increase_lifetime();
}


void free_messages()
{
	int rc;
	
	    rc = MB_Clear(b_pointsource);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'pointsource' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'pointsource' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'pointsource' board is locked\n");
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
	
	    rc = MB_Clear(b_position);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'position' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'position' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'position' board is locked\n");
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
	FLAME_m_pointsource_composite_params = NULL;

	    rc = MB_Create(&b_pointsource, sizeof(m_pointsource));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'pointsource' board\n");
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
	FLAME_m_position_composite_params = NULL;

	    rc = MB_Create(&b_position, sizeof(m_position));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'position' board\n");
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
	
	dcc_end_state = init_dcc_state();

	dcc_start_state = init_dcc_state();

	ob_end_state = init_ob_state();

	ob_moving_state = init_ob_state();

	ob_start_state = init_ob_state();

	oc_start_state = init_oc_state();

	oc_end_state = init_oc_state();

	oc_signal_state = init_oc_state();

	pointsource_increase_lifetime_state = init_pointsource_state();

	pointsource_end_state = init_pointsource_state();

	pointsource_signal_state = init_pointsource_state();

	pointsource_start_state = init_pointsource_state();

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



void init_gridcell(/*@out@*/ gridcell * temp)
{
	(*temp).xcoord = 0;
	(*temp).ycoord = 0;
	(*temp).length = 0;

}

void init_gridcell_static_array(/*@out@*/ gridcell * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_gridcell(&array[i]);
}

void free_gridcell(gridcell * temp)
{

}

void free_gridcell_static_array(gridcell * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_gridcell(&array[i]);
}

void copy_gridcell(gridcell * from, gridcell * to)
{
	(*to).xcoord = (*from).xcoord;
	(*to).ycoord = (*from).ycoord;
	(*to).length = (*from).length;
}

void copy_gridcell_static_array(gridcell * from, gridcell * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_gridcell(&from[i], &to[i]);
	}
}


void init_ps(/*@out@*/ ps * temp)
{
	(*temp).locationx = 0;
	(*temp).locationy = 0;
	(*temp).base_conc = 0.0;
	(*temp).max_conc = 0.0;
	(*temp).current_conc = 0.0;
	(*temp).decay_exp = 0.0;
	(*temp).gradient_power = 0;
	(*temp).lifetime = 0;

}

void init_ps_static_array(/*@out@*/ ps * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_ps(&array[i]);
}

void free_ps(ps * temp)
{

}

void free_ps_static_array(ps * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_ps(&array[i]);
}

void copy_ps(ps * from, ps * to)
{
	(*to).locationx = (*from).locationx;
	(*to).locationy = (*from).locationy;
	(*to).base_conc = (*from).base_conc;
	(*to).max_conc = (*from).max_conc;
	(*to).current_conc = (*from).current_conc;
	(*to).decay_exp = (*from).decay_exp;
	(*to).gradient_power = (*from).gradient_power;
	(*to).lifetime = (*from).lifetime;
}

void copy_ps_static_array(ps * from, ps * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_ps(&from[i], &to[i]);
	}
}



xmachine_memory_dcc_state * init_dcc_state()
{
	xmachine_memory_dcc_state * current = (xmachine_memory_dcc_state *)malloc(sizeof(xmachine_memory_dcc_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_dcc * init_dcc_agent()
{
	xmachine_memory_dcc * current = (xmachine_memory_dcc *)malloc(sizeof(xmachine_memory_dcc));
	CHECK_POINTER(current);

	current->DiD_MFI = 0;
	init_gridcell(&current->geo);
	current->dormant = 0;

	return current;
}

void free_dcc_agent(xmachine_memory_dcc_holder * tmp, xmachine_memory_dcc_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_gridcell(&tmp->agent->geo);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_dcc_agent()
{
	current_xmachine_dcc = (xmachine_memory_dcc *)malloc(sizeof(xmachine_memory_dcc));
	CHECK_POINTER(current);

		current_xmachine_dcc->DiD_MFI = 0;
		init_gridcell(&current_xmachine_dcc->geo);
		current_xmachine_dcc->dormant = 0;
	
}

void unittest_free_dcc_agent()
{
	free_gridcell(&current_xmachine_dcc->geo);
	
	free(current_xmachine_dcc);
}

void free_dcc_agents()
{
	current_xmachine_dcc_holder = dcc_end_state->agents;
	while(current_xmachine_dcc_holder)
	{
		temp_xmachine_dcc_holder = current_xmachine_dcc_holder->next;
		free_dcc_agent(current_xmachine_dcc_holder, dcc_end_state);
		current_xmachine_dcc_holder = temp_xmachine_dcc_holder;
	}
	dcc_end_state->count = 0;
	current_xmachine_dcc_holder = dcc_start_state->agents;
	while(current_xmachine_dcc_holder)
	{
		temp_xmachine_dcc_holder = current_xmachine_dcc_holder->next;
		free_dcc_agent(current_xmachine_dcc_holder, dcc_start_state);
		current_xmachine_dcc_holder = temp_xmachine_dcc_holder;
	}
	dcc_start_state->count = 0;
}

void free_dcc_states()
{
	free(dcc_end_state);
	free(dcc_start_state);
}

void transition_dcc_agent(xmachine_memory_dcc_holder * tmp, xmachine_memory_dcc_state * from_state, xmachine_memory_dcc_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_dcc_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_dcc_agent_internal(xmachine_memory_dcc * agent, xmachine_memory_dcc_state * state)
{
	xmachine_memory_dcc_holder * current = (xmachine_memory_dcc_holder *)malloc(sizeof(xmachine_memory_dcc_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_dcc_agent(int DiD_MFI, gridcell * geo, int dormant)
 * \brief Add dcc X-machine to the current being used X-machine list.
 * \param DiD_MFI Variable for the X-machine memory.
 * \param geo Variable for the X-machine memory.
 * \param dormant Variable for the X-machine memory.
 */
void add_dcc_agent(int DiD_MFI, gridcell geo, int dormant)
{
	xmachine_memory_dcc * current;

	current = init_dcc_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_dcc_next_state = dcc_start_state;
	add_dcc_agent_internal(current, current_xmachine_dcc_next_state);

	current->DiD_MFI = DiD_MFI;
	copy_gridcell(&geo, &current->geo);
	current->dormant = dormant;
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

	init_gridcell(&current->geo);
	current->celltype = 0;

	return current;
}

void free_ob_agent(xmachine_memory_ob_holder * tmp, xmachine_memory_ob_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_gridcell(&tmp->agent->geo);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_ob_agent()
{
	current_xmachine_ob = (xmachine_memory_ob *)malloc(sizeof(xmachine_memory_ob));
	CHECK_POINTER(current);

		init_gridcell(&current_xmachine_ob->geo);
		current_xmachine_ob->celltype = 0;
	
}

void unittest_free_ob_agent()
{
	free_gridcell(&current_xmachine_ob->geo);
	
	free(current_xmachine_ob);
}

void free_ob_agents()
{
	current_xmachine_ob_holder = ob_end_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		free_ob_agent(current_xmachine_ob_holder, ob_end_state);
		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	ob_end_state->count = 0;
	current_xmachine_ob_holder = ob_moving_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		free_ob_agent(current_xmachine_ob_holder, ob_moving_state);
		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	ob_moving_state->count = 0;
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
	free(ob_end_state);
	free(ob_moving_state);
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

/** \fn void add_ob_agent(gridcell * geo, int celltype)
 * \brief Add ob X-machine to the current being used X-machine list.
 * \param geo Variable for the X-machine memory.
 * \param celltype Variable for the X-machine memory.
 */
void add_ob_agent(gridcell geo, int celltype)
{
	xmachine_memory_ob * current;

	current = init_ob_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_ob_next_state = ob_start_state;
	add_ob_agent_internal(current, current_xmachine_ob_next_state);

	copy_gridcell(&geo, &current->geo);
	current->celltype = celltype;
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

	current->id = ' ';
	init_gridcell(&current->geo);

	return current;
}

void free_oc_agent(xmachine_memory_oc_holder * tmp, xmachine_memory_oc_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_gridcell(&tmp->agent->geo);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_oc_agent()
{
	current_xmachine_oc = (xmachine_memory_oc *)malloc(sizeof(xmachine_memory_oc));
	CHECK_POINTER(current);

		current_xmachine_oc->id = ' ';
		init_gridcell(&current_xmachine_oc->geo);
	
}

void unittest_free_oc_agent()
{
	free_gridcell(&current_xmachine_oc->geo);
	
	free(current_xmachine_oc);
}

void free_oc_agents()
{
	current_xmachine_oc_holder = oc_start_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_start_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_start_state->count = 0;
	current_xmachine_oc_holder = oc_end_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_end_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_end_state->count = 0;
	current_xmachine_oc_holder = oc_signal_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		free_oc_agent(current_xmachine_oc_holder, oc_signal_state);
		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	oc_signal_state->count = 0;
}

void free_oc_states()
{
	free(oc_start_state);
	free(oc_end_state);
	free(oc_signal_state);
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

/** \fn void add_oc_agent(char id, gridcell * geo)
 * \brief Add oc X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param geo Variable for the X-machine memory.
 */
void add_oc_agent(char id, gridcell geo)
{
	xmachine_memory_oc * current;

	current = init_oc_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_oc_next_state = oc_start_state;
	add_oc_agent_internal(current, current_xmachine_oc_next_state);

	current->id = id;
	copy_gridcell(&geo, &current->geo);
}

xmachine_memory_pointsource_state * init_pointsource_state()
{
	xmachine_memory_pointsource_state * current = (xmachine_memory_pointsource_state *)malloc(sizeof(xmachine_memory_pointsource_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_pointsource * init_pointsource_agent()
{
	xmachine_memory_pointsource * current = (xmachine_memory_pointsource *)malloc(sizeof(xmachine_memory_pointsource));
	CHECK_POINTER(current);

	init_ps(&current->descrip);
	current->active = 0;
	current->source_start = 0;

	return current;
}

void free_pointsource_agent(xmachine_memory_pointsource_holder * tmp, xmachine_memory_pointsource_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_ps(&tmp->agent->descrip);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_pointsource_agent()
{
	current_xmachine_pointsource = (xmachine_memory_pointsource *)malloc(sizeof(xmachine_memory_pointsource));
	CHECK_POINTER(current);

		init_ps(&current_xmachine_pointsource->descrip);
		current_xmachine_pointsource->active = 0;
		current_xmachine_pointsource->source_start = 0;
	
}

void unittest_free_pointsource_agent()
{
	free_ps(&current_xmachine_pointsource->descrip);
	
	free(current_xmachine_pointsource);
}

void free_pointsource_agents()
{
	current_xmachine_pointsource_holder = pointsource_increase_lifetime_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_increase_lifetime_state);
		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	pointsource_increase_lifetime_state->count = 0;
	current_xmachine_pointsource_holder = pointsource_end_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_end_state);
		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	pointsource_end_state->count = 0;
	current_xmachine_pointsource_holder = pointsource_signal_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_signal_state);
		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	pointsource_signal_state->count = 0;
	current_xmachine_pointsource_holder = pointsource_start_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state);
		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	pointsource_start_state->count = 0;
}

void free_pointsource_states()
{
	free(pointsource_increase_lifetime_state);
	free(pointsource_end_state);
	free(pointsource_signal_state);
	free(pointsource_start_state);
}

void transition_pointsource_agent(xmachine_memory_pointsource_holder * tmp, xmachine_memory_pointsource_state * from_state, xmachine_memory_pointsource_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_pointsource_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_pointsource_agent_internal(xmachine_memory_pointsource * agent, xmachine_memory_pointsource_state * state)
{
	xmachine_memory_pointsource_holder * current = (xmachine_memory_pointsource_holder *)malloc(sizeof(xmachine_memory_pointsource_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_pointsource_agent(ps * descrip, int active, int source_start)
 * \brief Add pointsource X-machine to the current being used X-machine list.
 * \param descrip Variable for the X-machine memory.
 * \param active Variable for the X-machine memory.
 * \param source_start Variable for the X-machine memory.
 */
void add_pointsource_agent(ps descrip, int active, int source_start)
{
	xmachine_memory_pointsource * current;

	current = init_pointsource_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_pointsource_next_state = pointsource_start_state;
	add_pointsource_agent_internal(current, current_xmachine_pointsource_next_state);

	copy_ps(&descrip, &current->descrip);
	current->active = active;
	current->source_start = source_start;
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_dcc_agents();
	free_ob_agents();
	free_oc_agents();
	free_pointsource_agents();
	
}


/** \fn void set_DiD_MFI(int DiD_MFI)
 * \brief Set DiD_MFI memory variable for current X-machine.
 * \param DiD_MFI New value for variable.
 */
void set_DiD_MFI(int DiD_MFI)
{
	if(current_xmachine->xmachine_dcc) (*current_xmachine->xmachine_dcc).DiD_MFI = DiD_MFI;
}

/** \fn int get_DiD_MFI()
 * \brief Get DiD_MFI memory variable from current X-machine.
 * \return Value for variable.
 */
int get_DiD_MFI()
{
	if(current_xmachine->xmachine_dcc) return (*current_xmachine->xmachine_dcc).DiD_MFI;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn gridcell get_geo()
 * \brief Get geo memory variable from current X-machine.
 * \return Value for variable.
 */
gridcell * get_geo()
{
	if(current_xmachine->xmachine_dcc) return &(*current_xmachine->xmachine_dcc).geo;
	if(current_xmachine->xmachine_ob) return &(*current_xmachine->xmachine_ob).geo;
	if(current_xmachine->xmachine_oc) return &(*current_xmachine->xmachine_oc).geo;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_dormant(int dormant)
 * \brief Set dormant memory variable for current X-machine.
 * \param dormant New value for variable.
 */
void set_dormant(int dormant)
{
	if(current_xmachine->xmachine_dcc) (*current_xmachine->xmachine_dcc).dormant = dormant;
}

/** \fn int get_dormant()
 * \brief Get dormant memory variable from current X-machine.
 * \return Value for variable.
 */
int get_dormant()
{
	if(current_xmachine->xmachine_dcc) return (*current_xmachine->xmachine_dcc).dormant;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_celltype(int celltype)
 * \brief Set celltype memory variable for current X-machine.
 * \param celltype New value for variable.
 */
void set_celltype(int celltype)
{
	if(current_xmachine->xmachine_ob) (*current_xmachine->xmachine_ob).celltype = celltype;
}

/** \fn int get_celltype()
 * \brief Get celltype memory variable from current X-machine.
 * \return Value for variable.
 */
int get_celltype()
{
	if(current_xmachine->xmachine_ob) return (*current_xmachine->xmachine_ob).celltype;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_id(char id)
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(char id)
{
	if(current_xmachine->xmachine_oc) (*current_xmachine->xmachine_oc).id = id;
}

/** \fn char get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
char get_id()
{
	if(current_xmachine->xmachine_oc) return (*current_xmachine->xmachine_oc).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (char)0;
}

/** \fn ps get_descrip()
 * \brief Get descrip memory variable from current X-machine.
 * \return Value for variable.
 */
ps * get_descrip()
{
	if(current_xmachine->xmachine_pointsource) return &(*current_xmachine->xmachine_pointsource).descrip;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_active(int active)
 * \brief Set active memory variable for current X-machine.
 * \param active New value for variable.
 */
void set_active(int active)
{
	if(current_xmachine->xmachine_pointsource) (*current_xmachine->xmachine_pointsource).active = active;
}

/** \fn int get_active()
 * \brief Get active memory variable from current X-machine.
 * \return Value for variable.
 */
int get_active()
{
	if(current_xmachine->xmachine_pointsource) return (*current_xmachine->xmachine_pointsource).active;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_source_start(int source_start)
 * \brief Set source_start memory variable for current X-machine.
 * \param source_start New value for variable.
 */
void set_source_start(int source_start)
{
	if(current_xmachine->xmachine_pointsource) (*current_xmachine->xmachine_pointsource).source_start = source_start;
}

/** \fn int get_source_start()
 * \brief Get source_start memory variable from current X-machine.
 * \return Value for variable.
 */
int get_source_start()
{
	if(current_xmachine->xmachine_pointsource) return (*current_xmachine->xmachine_pointsource).source_start;

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
    /*if (current_xmachine->xmachine_dcc) value = current_xmachine->xmachine_dcc->;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->;*/
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->;*/
    /*if (current_xmachine->xmachine_pointsource) value = current_xmachine->xmachine_pointsource->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_dcc) value = current_xmachine->xmachine_dcc->;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->;*/
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->id;*/
    /*if (current_xmachine->xmachine_pointsource) value = current_xmachine->xmachine_pointsource->;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_dcc) value = current_xmachine->xmachine_dcc->0.0;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->0.0;*/
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->0.0;*/
    /*if (current_xmachine->xmachine_pointsource) value = current_xmachine->xmachine_pointsource->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_dcc) value = current_xmachine->xmachine_dcc->0.0;*/
    /*if (current_xmachine->xmachine_ob) value = current_xmachine->xmachine_ob->0.0;*/
    /*if (current_xmachine->xmachine_oc) value = current_xmachine->xmachine_oc->0.0;*/
    /*if (current_xmachine->xmachine_pointsource) value = current_xmachine->xmachine_pointsource->0.0;*/

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
	current->pointsource_messages = NULL;
	current->position_messages = NULL;


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
	free_dcc_states();
	free_ob_states();
	free_oc_states();
	free_pointsource_states();


	/* Free index maps */


	/* Free message boards */

	rc = MB_Delete(&b_pointsource);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'pointsource' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pointsource' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pointsource' board is locked\n");
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

	rc = MB_Delete(&b_position);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'position' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'position' board is locked\n");
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
		if(current_xmachine->xmachine_dcc != NULL)
		{
			x_xmachine = current_xmachine->xmachine_dcc->0.0;
			y_xmachine = current_xmachine->xmachine_dcc->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_ob != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ob->0.0;
			y_xmachine = current_xmachine->xmachine_ob->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_oc != NULL)
		{
			x_xmachine = current_xmachine->xmachine_oc->0.0;
			y_xmachine = current_xmachine->xmachine_oc->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_pointsource != NULL)
		{
			x_xmachine = current_xmachine->xmachine_pointsource->0.0;
			y_xmachine = current_xmachine->xmachine_pointsource->0.0;
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

/* Functions for the gridcell datatype */
/** \fn gridcell_array * init_gridcell_array()
 * \brief Allocate memory for a dynamic gridcell array.
 * \return gridcell_array Pointer to the new dynamic gridcell array.
 */
void init_gridcell_array(gridcell_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (gridcell *)malloc(ARRAY_BLOCK_SIZE * sizeof(gridcell));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_gridcell_array(gridcell_array* array)
* \brief Reset the gridcell array to hold nothing.
* \param array Pointer to the dynamic gridcell array.
*/
void reset_gridcell_array(gridcell_array * array)
{
	(*array).size = 0;
}

/** \fn void free_gridcell_array(gridcell_array * array)
* \brief Free the memory of a dynamic gridcell array.
* \param array Pointer to the dynamic gridcell array.
*/
void free_gridcell_array(gridcell_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_gridcell(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_gridcell_array(gridcell_array * from, gridcell_array * to)
{
	int i;

	//to = init_gridcell_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_gridcell(to, (*from).array[i].xcoord, (*from).array[i].ycoord, (*from).array[i].length);
	}
}

/** \fn void add_gridcell(gridcell_array * array, int xcoord, int ycoord, int length)
* \brief Add an gridcell to the dynamic gridcell array.
* \param array Pointer to the dynamic gridcell array.
* \param new_int The gridcell to add
*/
void add_gridcell(gridcell_array * array,  int xcoord,  int ycoord,  int length)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (gridcell *)realloc((*array).array, ((*array).total_size * sizeof(gridcell)));
	}
	init_gridcell(&(*array).array[(*array).size]);
	(*array).array[(*array).size].xcoord = xcoord;
	(*array).array[(*array).size].ycoord = ycoord;
	(*array).array[(*array).size].length = length;

	(*array).size++;
}

/** \fn void remove_gridcell(gridcell_array * array, int index)
 * \brief Remove an gridcell from a dynamic gridcell array.
 * \param array Pointer to the dynamic gridcell array.
 * \param index The index of the gridcell to remove.
 */
void remove_gridcell(gridcell_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_gridcell(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_gridcell(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the ps datatype */
/** \fn ps_array * init_ps_array()
 * \brief Allocate memory for a dynamic ps array.
 * \return ps_array Pointer to the new dynamic ps array.
 */
void init_ps_array(ps_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (ps *)malloc(ARRAY_BLOCK_SIZE * sizeof(ps));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_ps_array(ps_array* array)
* \brief Reset the ps array to hold nothing.
* \param array Pointer to the dynamic ps array.
*/
void reset_ps_array(ps_array * array)
{
	(*array).size = 0;
}

/** \fn void free_ps_array(ps_array * array)
* \brief Free the memory of a dynamic ps array.
* \param array Pointer to the dynamic ps array.
*/
void free_ps_array(ps_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_ps(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_ps_array(ps_array * from, ps_array * to)
{
	int i;

	//to = init_ps_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_ps(to, (*from).array[i].locationx, (*from).array[i].locationy, (*from).array[i].base_conc, (*from).array[i].max_conc, (*from).array[i].current_conc, (*from).array[i].decay_exp, (*from).array[i].gradient_power, (*from).array[i].lifetime);
	}
}

/** \fn void add_ps(ps_array * array, int locationx, int locationy, double base_conc, double max_conc, double current_conc, double decay_exp, int gradient_power, int lifetime)
* \brief Add an ps to the dynamic ps array.
* \param array Pointer to the dynamic ps array.
* \param new_int The ps to add
*/
void add_ps(ps_array * array,  int locationx,  int locationy,  double base_conc,  double max_conc,  double current_conc,  double decay_exp,  int gradient_power,  int lifetime)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (ps *)realloc((*array).array, ((*array).total_size * sizeof(ps)));
	}
	init_ps(&(*array).array[(*array).size]);
	(*array).array[(*array).size].locationx = locationx;
	(*array).array[(*array).size].locationy = locationy;
	(*array).array[(*array).size].base_conc = base_conc;
	(*array).array[(*array).size].max_conc = max_conc;
	(*array).array[(*array).size].current_conc = current_conc;
	(*array).array[(*array).size].decay_exp = decay_exp;
	(*array).array[(*array).size].gradient_power = gradient_power;
	(*array).array[(*array).size].lifetime = lifetime;

	(*array).size++;
}

/** \fn void remove_ps(ps_array * array, int index)
 * \brief Remove an ps from a dynamic ps array.
 * \param array Pointer to the dynamic ps array.
 * \param index The index of the ps to remove.
 */
void remove_ps(ps_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_ps(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_ps(&(*array).array[i+1], &(*array).array[i]);
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
int FLAME_get_environment_variable_unitum()
{
	return FLAME_environment_variable_unitum;
}
int FLAME_get_environment_variable_OC_speed()
{
	return FLAME_environment_variable_OC_speed;
}


