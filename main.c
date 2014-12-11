/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"
#define COMPACT_PRINTOUT_P_THRESHOLD 8

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
	/* Timing variables */
	double start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[1000];
	char inputpath[1000];
	char * c;
	int lastd = 0;
	int i;
	int rc;
	int iteration_number = 0;
	int iteration_total;
	int * p_iteration_number = &iteration_number;
	//xmachine_memory_dcc * temp_xmachine_dcc;
	//xmachine_memory_ob * temp_xmachine_ob;
	//xmachine_memory_oc * temp_xmachine_oc;
	//xmachine_memory_pointsource * temp_xmachine_pointsource;

	int FLAME_pointsource_message_board_write;
	int FLAME_pointsource_message_board_read;
	int FLAME_position_message_board_write;
	int FLAME_position_message_board_read;

	/* Particle cloud data */
	double cloud_data[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
	/* Count to debug function branches */
	int FLAME_debug_count;

/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;



	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */

	

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
    
	/* For backwards compatabilty allocate current_xmachine */
	current_xmachine = (xmachine *)malloc(sizeof(xmachine));
	if(current_xmachine == NULL) {printf("**** ERROR in Memory check current_xmachine\n");exit(EXIT_FAILURE);}
	/*CHECK_POINTER(current_xmachine);*/

	/* Initialise pointers */
	initialise_pointers();


	printf("FLAME Application: Dormant Cancer Cells \n");


	printf("Debug mode enabled \n");
FLAME_debug_count = 0;
/* Use to stop compiler warnings if not used */
if(FLAME_debug_count == 0) {}




if(argc < 2)
	{

		printf("Usage: %s <number of iterations> [<states_directory>]/<init_state> <partitions> [-f # | -f #+#]\n",argv[0]);
		printf("\t-f\tOutput frequency, 1st # is frequency, 2nd # is the offset if required\n");



		exit(0);
	}
	iteration_total = atoi(argv[1]);
printf("Iterations: %i\n", iteration_total);

	/* Read initial states of x-machines */
	if(argc < 3)
	{
		printf("Need two parameters\n");
		exit(0);
	}
	strcpy(inputpath, argv[2]);
/*printf("Initial states: %s\n", inputpath);*/

	i = 0;
	lastd = -1;
	while(inputpath[i] != '\0')
	{
		/* For windows directories */
		if(inputpath[i] == '\\') lastd=i;
		/* For unix directories */
		if(inputpath[i] == '/') lastd=i;
		i++;
	}
	strcpy(outputpath, inputpath);
	outputpath[lastd+1] = '\0';

/*printf("Ouput dir: %s\n", outputpath);*/


	/* Read number of space partitions (1 by default) */
	totalnodes = 1;
	if(argc > 3)
	{
		totalnodes = atoi(argv[3]);
	}


	i = 3;
	while(argc > i)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			if(argc > (i+1))
			{
				output_offset = 0;
				/* Find offset, separated by the char '+' */
				c = strchr(argv[(i+1)], '+');
				if(c == NULL)
				{
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d\n", output_frequency);
				}
				else
				{
					output_offset = atoi(argv[(i+1)]+(c-argv[(i+1)])+1);
					argv[(i+1)][c-argv[(i+1)]] = '\0';
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d with offset %d\n", output_frequency, output_offset);
				}

				if(output_frequency == 0)
				{
					printf("Output frequency cannot be zero\n");
					exit(0);
				}

				i++;
			}
			else
			{
				printf("Output frequency number not defined\n");
				exit(0);
			}
		}
		/* Partitioning method: -g = geometric, -r = round-robin */
		if(strcmp(argv[i],"-g") == 0) partition_method = 1;
		if(strcmp(argv[i],"-r") == 0) partition_method = 2;
		i++;
	}


	    /* Read initial data into p_xmachine  */

       //agent_list = p_xmachine;
       readinitialstates(inputpath, outputpath, p_iteration_number, cloud_data, partition_method, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();





    /* Partition data */
    /* stc: no partitions in serial */
	//partition_data(totalnodes, agent_list, cloud_data, partition_method);



/* Use MB_IndexMap routines from libmboard v0.2 */
/* For each agent constant (that is used in a filter(?))
 * declare an index map handle */



		/*i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);*/

        /* restore current_node pointer */
		//current_node = *p_node_info;



	/* Start log file (now so that xvisualiser can read straight away) */

	/* Write log file */
	sprintf(logfilepath, "%slog.xml", outputpath);
	if((file = fopen(logfilepath, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", logfilepath);
		exit(0);
	}
	(void)fputs("<model_run>\n", file);
	(void)fputs("<codetype>", file);
	(void)fputs("serial", file);

	(void)fputs("</codetype>\n", file);
	(void)fputs("<nodes>", file);
	sprintf(data, "%i", totalnodes);
	(void)fputs(data, file);
	(void)fputs("</nodes>\n", file);

	/* print timer into */
	(void)fputs("<!-- <time> unit: milliseconds -->\n", file);

	sprintf(data, "unspecified");
	
	(void)fputs("<!-- <time> timer resolution: ", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);

	start = get_time();
	stop = get_time();
	sprintf(data, "%.2e ms", (stop - start) * 1000.0);
	(void)fputs("<!-- <time> timer overhead: ~", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);


	(void)fclose(file);


	/* For each message check if their exists agents that input/output the message */
	FLAME_pointsource_message_board_write = 0;
	FLAME_pointsource_message_board_read = 0;
	/* Sending agents */
	if(pointsource_start_state->agents != NULL) FLAME_pointsource_message_board_write = 1;
	
	/* Reading agents */
	if(ob_start_state->agents != NULL) FLAME_pointsource_message_board_read = 1;
	if(oc_start_state->agents != NULL) FLAME_pointsource_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_pointsource_message_board_write == 0 &&
		FLAME_pointsource_message_board_read == 0)
			rc = MB_SetAccessMode(b_pointsource, MB_MODE_IDLE);
	if(FLAME_pointsource_message_board_write == 1 &&
		FLAME_pointsource_message_board_read == 0)
			rc = MB_SetAccessMode(b_pointsource, MB_MODE_WRITEONLY);
	if(FLAME_pointsource_message_board_write == 0 &&
		FLAME_pointsource_message_board_read == 1)
			rc = MB_SetAccessMode(b_pointsource, MB_MODE_READONLY);
	if(FLAME_pointsource_message_board_write == 1 &&
		FLAME_pointsource_message_board_read == 1)
			rc = MB_SetAccessMode(b_pointsource, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'pointsource' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_position_message_board_write = 0;
	FLAME_position_message_board_read = 0;
	/* Sending agents */
	if(ob_start_state->agents != NULL) FLAME_position_message_board_write = 1;
	if(oc_start_state->agents != NULL) FLAME_position_message_board_write = 1;
	
	/* Reading agents */
	if(dcc_start_state->agents != NULL) FLAME_position_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_position_message_board_write == 0 &&
		FLAME_position_message_board_read == 0)
			rc = MB_SetAccessMode(b_position, MB_MODE_IDLE);
	if(FLAME_position_message_board_write == 1 &&
		FLAME_position_message_board_read == 0)
			rc = MB_SetAccessMode(b_position, MB_MODE_WRITEONLY);
	if(FLAME_position_message_board_write == 0 &&
		FLAME_position_message_board_read == 1)
			rc = MB_SetAccessMode(b_position, MB_MODE_READONLY);
	if(FLAME_position_message_board_write == 1 &&
		FLAME_position_message_board_read == 1)
			rc = MB_SetAccessMode(b_position, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'position' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	
	
	/* Start timing */
	start = get_time();

	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = get_time();

		/* Print out iteration number */
		
		fprintf(stdout, "Iteration - %d\n", iteration_loop);
		(void)fflush(stdout);
        
		/* START OF ITERATION */
		
		/* Start sync message boards that don't write */
		if(FLAME_pointsource_message_board_write == 0)
		{
			/*printf("%d> pointsource message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_pointsource)\n");
			rc = MB_SyncStart(b_pointsource);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_pointsource)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'pointsource' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_position_message_board_write == 0)
		{
			/*printf("%d> position message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_position)\n");
			rc = MB_SyncStart(b_position);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_position)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'position' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		
	/* DEBUG: States with branching functions */
		current_xmachine_dcc_holder = dcc_start_state->agents;
		while(current_xmachine_dcc_holder)
		{
			FLAME_debug_count = 0;
			/* Function: divide */
			if(FLAME_condition_dcc_divide_start_end(current_xmachine_dcc_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: respond */
			if(FLAME_condition_dcc_respond_start_end(current_xmachine_dcc_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'dcc' leaving state 'start'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_dcc_holder = current_xmachine_dcc_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_pointsource_holder = pointsource_start_state->agents;
		while(current_xmachine_pointsource_holder)
		{
			FLAME_debug_count = 0;
			/* Function: inactive */
			if(FLAME_condition_pointsource_inactive_start_end(current_xmachine_pointsource_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: decay */
			if(FLAME_condition_pointsource_decay_start_signal(current_xmachine_pointsource_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: init */
			if(FLAME_condition_pointsource_init_start_signal(current_xmachine_pointsource_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'pointsource' leaving state 'start'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start signal_ob_position\n");
	current_xmachine_ob_holder = ob_start_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		current_xmachine_ob = current_xmachine_ob_holder->agent;
		current_xmachine_ob_next_state = ob_moving_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_ob = current_xmachine_ob;

		

		

			i = signal_ob_position();

		

			if(i == 1)
			{
				free_ob_agent(current_xmachine_ob_holder, ob_start_state);
			}
			else
			{
				transition_ob_agent(current_xmachine_ob_holder, ob_start_state, ob_moving_state);
			}
		

		current_xmachine_ob = NULL;

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish signal_ob_position\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start inactive\n");
	current_xmachine_pointsource_holder = pointsource_start_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		current_xmachine_pointsource = current_xmachine_pointsource_holder->agent;
		current_xmachine_pointsource_next_state = pointsource_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_pointsource = current_xmachine_pointsource;

		if(FLAME_condition_pointsource_inactive_start_end(current_xmachine_pointsource)==1)
		{

		

			i = inactive();

		

			if(i == 1)
			{
				free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state);
			}
			else
			{
				transition_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state, pointsource_end_state);
			}
		}

		current_xmachine_pointsource = NULL;

		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish inactive\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start decay\n");
	current_xmachine_pointsource_holder = pointsource_start_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		current_xmachine_pointsource = current_xmachine_pointsource_holder->agent;
		current_xmachine_pointsource_next_state = pointsource_signal_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_pointsource = current_xmachine_pointsource;

		if(FLAME_condition_pointsource_decay_start_signal(current_xmachine_pointsource)==1)
		{

		

			i = decay();

		

			if(i == 1)
			{
				free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state);
			}
			else
			{
				transition_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state, pointsource_signal_state);
			}
		}

		current_xmachine_pointsource = NULL;

		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish decay\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start init\n");
	current_xmachine_pointsource_holder = pointsource_start_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		current_xmachine_pointsource = current_xmachine_pointsource_holder->agent;
		current_xmachine_pointsource_next_state = pointsource_signal_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_pointsource = current_xmachine_pointsource;

		if(FLAME_condition_pointsource_init_start_signal(current_xmachine_pointsource)==1)
		{

		

			i = init();

		

			if(i == 1)
			{
				free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state);
			}
			else
			{
				transition_pointsource_agent(current_xmachine_pointsource_holder, pointsource_start_state, pointsource_signal_state);
			}
		}

		current_xmachine_pointsource = NULL;

		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish init\n");


/* End of layer number 0 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start signal\n");
	current_xmachine_pointsource_holder = pointsource_signal_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		current_xmachine_pointsource = current_xmachine_pointsource_holder->agent;
		current_xmachine_pointsource_next_state = pointsource_increase_lifetime_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_pointsource = current_xmachine_pointsource;

		

		

			i = signal();

		

			if(i == 1)
			{
				free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_signal_state);
			}
			else
			{
				transition_pointsource_agent(current_xmachine_pointsource_holder, pointsource_signal_state, pointsource_increase_lifetime_state);
			}
		

		current_xmachine_pointsource = NULL;

		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish signal\n");

	if(FLAME_pointsource_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_pointsource)\n");
		rc = MB_SyncStart(b_pointsource);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_pointsource)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'pointsource' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 1 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start increase_lifetime\n");
	current_xmachine_pointsource_holder = pointsource_increase_lifetime_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		current_xmachine_pointsource = current_xmachine_pointsource_holder->agent;
		current_xmachine_pointsource_next_state = pointsource_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_pointsource = current_xmachine_pointsource;

		

		

			i = increase_lifetime();

		

			if(i == 1)
			{
				free_pointsource_agent(current_xmachine_pointsource_holder, pointsource_increase_lifetime_state);
			}
			else
			{
				transition_pointsource_agent(current_xmachine_pointsource_holder, pointsource_increase_lifetime_state, pointsource_end_state);
			}
		

		current_xmachine_pointsource = NULL;

		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish increase_lifetime\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_pointsource_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_pointsource)\n");
		rc = MB_SyncComplete(b_pointsource);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_pointsource)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'pointsource' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'pointsource' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start move\n");
	current_xmachine_ob_holder = ob_moving_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		current_xmachine_ob = current_xmachine_ob_holder->agent;
		current_xmachine_ob_next_state = ob_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_ob = current_xmachine_ob;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = move();

		
		    rc = MB_Iterator_Delete(&i_pointsource);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pointsource' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pointsource' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_ob_agent(current_xmachine_ob_holder, ob_moving_state);
			}
			else
			{
				transition_ob_agent(current_xmachine_ob_holder, ob_moving_state, ob_end_state);
			}
		

		current_xmachine_ob = NULL;

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish move\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start move\n");
	current_xmachine_oc_holder = oc_start_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_signal_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = move();

		
		    rc = MB_Iterator_Delete(&i_pointsource);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pointsource' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pointsource' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_start_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_start_state, oc_signal_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish move\n");


/* End of layer number 2 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_pointsource_message_board_read == 0)
{
	/*printf("%d> pointsource message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_pointsource)\n");
	rc = MB_SyncComplete(b_pointsource);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_pointsource)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'pointsource' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'pointsource' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start signal_oc_position\n");
	current_xmachine_oc_holder = oc_signal_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		

			i = signal_oc_position();

		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_signal_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_signal_state, oc_end_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish signal_oc_position\n");

	if(FLAME_position_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_position)\n");
		rc = MB_SyncStart(b_position);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_position)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'position' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 3 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_position_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_position)\n");
		rc = MB_SyncComplete(b_position);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_position)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'position' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'position' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start respond\n");
	current_xmachine_dcc_holder = dcc_start_state->agents;
	while(current_xmachine_dcc_holder)
	{
		temp_xmachine_dcc_holder = current_xmachine_dcc_holder->next;
		current_xmachine_dcc = current_xmachine_dcc_holder->agent;
		current_xmachine_dcc_next_state = dcc_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_dcc = current_xmachine_dcc;

		if(FLAME_condition_dcc_respond_start_end(current_xmachine_dcc)==1)
		{

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = respond();

		
		    rc = MB_Iterator_Delete(&i_position);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'position' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'position' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_dcc_agent(current_xmachine_dcc_holder, dcc_start_state);
			}
			else
			{
				transition_dcc_agent(current_xmachine_dcc_holder, dcc_start_state, dcc_end_state);
			}
		}

		current_xmachine_dcc = NULL;

		current_xmachine_dcc_holder = temp_xmachine_dcc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish respond\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start divide\n");
	current_xmachine_dcc_holder = dcc_start_state->agents;
	while(current_xmachine_dcc_holder)
	{
		temp_xmachine_dcc_holder = current_xmachine_dcc_holder->next;
		current_xmachine_dcc = current_xmachine_dcc_holder->agent;
		current_xmachine_dcc_next_state = dcc_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_dcc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_pointsource = NULL;
		current_xmachine->xmachine_dcc = current_xmachine_dcc;

		if(FLAME_condition_dcc_divide_start_end(current_xmachine_dcc)==1)
		{

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = divide();

		
		    rc = MB_Iterator_Delete(&i_position);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'position' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'position' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_dcc_agent(current_xmachine_dcc_holder, dcc_start_state);
			}
			else
			{
				transition_dcc_agent(current_xmachine_dcc_holder, dcc_start_state, dcc_end_state);
			}
		}

		current_xmachine_dcc = NULL;

		current_xmachine_dcc_holder = temp_xmachine_dcc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish divide\n");


/* End of layer number 4 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_position_message_board_read == 0)
{
	/*printf("%d> position message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_position)\n");
	rc = MB_SyncComplete(b_position);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_position)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'position' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'position' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

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



	/*printf("dcc_end_state->count = %d\n", dcc_end_state->count);*/
	dcc_end_state->count = 0;

	/*printf("dcc_start_state->count = %d\n", dcc_start_state->count);*/
	dcc_start_state->count = 0;

	/*printf("ob_end_state->count = %d\n", ob_end_state->count);*/
	ob_end_state->count = 0;

	/*printf("ob_moving_state->count = %d\n", ob_moving_state->count);*/
	ob_moving_state->count = 0;

	/*printf("ob_start_state->count = %d\n", ob_start_state->count);*/
	ob_start_state->count = 0;

	/*printf("oc_start_state->count = %d\n", oc_start_state->count);*/
	oc_start_state->count = 0;

	/*printf("oc_end_state->count = %d\n", oc_end_state->count);*/
	oc_end_state->count = 0;

	/*printf("oc_signal_state->count = %d\n", oc_signal_state->count);*/
	oc_signal_state->count = 0;

	/*printf("pointsource_increase_lifetime_state->count = %d\n", pointsource_increase_lifetime_state->count);*/
	pointsource_increase_lifetime_state->count = 0;

	/*printf("pointsource_end_state->count = %d\n", pointsource_end_state->count);*/
	pointsource_end_state->count = 0;

	/*printf("pointsource_signal_state->count = %d\n", pointsource_signal_state->count);*/
	pointsource_signal_state->count = 0;

	/*printf("pointsource_start_state->count = %d\n", pointsource_start_state->count);*/
	pointsource_start_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_dcc_holder = dcc_end_state->agents;
	while(current_xmachine_dcc_holder)
	{
		temp_xmachine_dcc_holder = current_xmachine_dcc_holder->next;
		transition_dcc_agent(current_xmachine_dcc_holder, dcc_end_state, dcc_start_state);

		current_xmachine_dcc_holder = temp_xmachine_dcc_holder;
	}

	current_xmachine_ob_holder = ob_end_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		transition_ob_agent(current_xmachine_ob_holder, ob_end_state, ob_start_state);

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}

	current_xmachine_oc_holder = oc_end_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		transition_oc_agent(current_xmachine_oc_holder, oc_end_state, oc_start_state);

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}

	current_xmachine_pointsource_holder = pointsource_end_state->agents;
	while(current_xmachine_pointsource_holder)
	{
		temp_xmachine_pointsource_holder = current_xmachine_pointsource_holder->next;
		transition_pointsource_agent(current_xmachine_pointsource_holder, pointsource_end_state, pointsource_start_state);

		current_xmachine_pointsource_holder = temp_xmachine_pointsource_holder;
	}

    if(iteration_loop%output_frequency == output_offset)
    {
        saveiterationdata(iteration_loop);
    }

		/* Calculate if any agents need to jump S.P. */
		/* propagate_agents(); */
	/* Save iteration time to log file */

		if((file = fopen(logfilepath, "a"))==NULL)
		{
			printf("Error: cannot open file '%s' for writing\n", logfilepath);
			exit(0);
		}
		(void)fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		(void)fputs(data, file);
		(void)fputs("</no><time>", file);
		sprintf(data, "%d", (int)((get_time() - interval) * 1000) );
		(void)fputs(data, file);
		(void)fputs("</time></iteration>\n", file);
		(void)fclose(file);

	}

    

	/* Stop timing and print total time */
	stop = get_time();
	total_time = stop - start;
	printf("Execution time - %d:%02d:%03d [mins:secs:msecs]\n",
       (int)(total_time/60), ((int)total_time)%60, (((int)(total_time * 1000.0)) % 1000));

	clean_up(0);

	/* Exit successfully by returning zero to Operating System */
	return 0;
}
