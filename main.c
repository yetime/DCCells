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
	//xmachine_memory_oc * temp_xmachine_oc;
	//xmachine_memory_ob * temp_xmachine_ob;
	//xmachine_memory_bmu * temp_xmachine_bmu;
	//xmachine_memory_environment * temp_xmachine_environment;

	int FLAME_oc_position_message_board_write;
	int FLAME_oc_position_message_board_read;
	int FLAME_ob_position_message_board_write;
	int FLAME_ob_position_message_board_read;
	int FLAME_fusion_message_board_write;
	int FLAME_fusion_message_board_read;
	int FLAME_fusion_signal_message_board_write;
	int FLAME_fusion_signal_message_board_read;

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
	/* Disable this check (if cond.) cause it messes up situations where agents are not created yet... let's see what the consequences are ;-) */
	FLAME_oc_position_message_board_write = 0;
	FLAME_oc_position_message_board_read = 0; 
	 FLAME_oc_position_message_board_write = 1;
	 
	 FLAME_oc_position_message_board_read = 1;
	 FLAME_oc_position_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_oc_position_message_board_write == 0 &&
		FLAME_oc_position_message_board_read == 0)
			rc = MB_SetAccessMode(b_oc_position, MB_MODE_IDLE);
	if(FLAME_oc_position_message_board_write == 1 &&
		FLAME_oc_position_message_board_read == 0)
			rc = MB_SetAccessMode(b_oc_position, MB_MODE_WRITEONLY);
	if(FLAME_oc_position_message_board_write == 0 &&
		FLAME_oc_position_message_board_read == 1)
			rc = MB_SetAccessMode(b_oc_position, MB_MODE_READONLY);
	if(FLAME_oc_position_message_board_write == 1 &&
		FLAME_oc_position_message_board_read == 1)
			rc = MB_SetAccessMode(b_oc_position, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'oc_position' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_ob_position_message_board_write = 0;
	FLAME_ob_position_message_board_read = 0; 
	 FLAME_ob_position_message_board_write = 1;
	 
	 FLAME_ob_position_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_ob_position_message_board_write == 0 &&
		FLAME_ob_position_message_board_read == 0)
			rc = MB_SetAccessMode(b_ob_position, MB_MODE_IDLE);
	if(FLAME_ob_position_message_board_write == 1 &&
		FLAME_ob_position_message_board_read == 0)
			rc = MB_SetAccessMode(b_ob_position, MB_MODE_WRITEONLY);
	if(FLAME_ob_position_message_board_write == 0 &&
		FLAME_ob_position_message_board_read == 1)
			rc = MB_SetAccessMode(b_ob_position, MB_MODE_READONLY);
	if(FLAME_ob_position_message_board_write == 1 &&
		FLAME_ob_position_message_board_read == 1)
			rc = MB_SetAccessMode(b_ob_position, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'ob_position' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_fusion_message_board_write = 0;
	FLAME_fusion_message_board_read = 0; 
	 FLAME_fusion_message_board_write = 1;
	 
	 FLAME_fusion_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_fusion_message_board_write == 0 &&
		FLAME_fusion_message_board_read == 0)
			rc = MB_SetAccessMode(b_fusion, MB_MODE_IDLE);
	if(FLAME_fusion_message_board_write == 1 &&
		FLAME_fusion_message_board_read == 0)
			rc = MB_SetAccessMode(b_fusion, MB_MODE_WRITEONLY);
	if(FLAME_fusion_message_board_write == 0 &&
		FLAME_fusion_message_board_read == 1)
			rc = MB_SetAccessMode(b_fusion, MB_MODE_READONLY);
	if(FLAME_fusion_message_board_write == 1 &&
		FLAME_fusion_message_board_read == 1)
			rc = MB_SetAccessMode(b_fusion, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'fusion' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_fusion_signal_message_board_write = 0;
	FLAME_fusion_signal_message_board_read = 0; 
	 FLAME_fusion_signal_message_board_write = 1;
	 
	 FLAME_fusion_signal_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_fusion_signal_message_board_write == 0 &&
		FLAME_fusion_signal_message_board_read == 0)
			rc = MB_SetAccessMode(b_fusion_signal, MB_MODE_IDLE);
	if(FLAME_fusion_signal_message_board_write == 1 &&
		FLAME_fusion_signal_message_board_read == 0)
			rc = MB_SetAccessMode(b_fusion_signal, MB_MODE_WRITEONLY);
	if(FLAME_fusion_signal_message_board_write == 0 &&
		FLAME_fusion_signal_message_board_read == 1)
			rc = MB_SetAccessMode(b_fusion_signal, MB_MODE_READONLY);
	if(FLAME_fusion_signal_message_board_write == 1 &&
		FLAME_fusion_signal_message_board_read == 1)
			rc = MB_SetAccessMode(b_fusion_signal, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'fusion_signal' board\n");
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
		if(FLAME_oc_position_message_board_write == 0)
		{
			/*printf("%d> oc_position message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_oc_position)\n");
			rc = MB_SyncStart(b_oc_position);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_oc_position)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'oc_position' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_ob_position_message_board_write == 0)
		{
			/*printf("%d> ob_position message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_ob_position)\n");
			rc = MB_SyncStart(b_ob_position);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_ob_position)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'ob_position' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_fusion_message_board_write == 0)
		{
			/*printf("%d> fusion message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fusion)\n");
			rc = MB_SyncStart(b_fusion);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fusion)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'fusion' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_fusion_signal_message_board_write == 0)
		{
			/*printf("%d> fusion_signal message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fusion_signal)\n");
			rc = MB_SyncStart(b_fusion_signal);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fusion_signal)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'fusion_signal' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		
	/* DEBUG: States with branching functions */
		current_xmachine_oc_holder = oc_start_state->agents;
		while(current_xmachine_oc_holder)
		{
			FLAME_debug_count = 0;
			/* Function: signal_oc_position */
			if(FLAME_condition_oc_signal_oc_position_start_1(current_xmachine_oc_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: initialize_oc */
			if(FLAME_condition_oc_initialize_oc_start_end(current_xmachine_oc_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'oc' leaving state 'start'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_oc_holder = current_xmachine_oc_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_ob_holder = ob_start_state->agents;
		while(current_xmachine_ob_holder)
		{
			FLAME_debug_count = 0;
			/* Function: signal_ob_position */
			if(FLAME_condition_ob_signal_ob_position_start_1(current_xmachine_ob_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: initialize_ob */
			if(FLAME_condition_ob_initialize_ob_start_end(current_xmachine_ob_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'ob' leaving state 'start'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_ob_holder = current_xmachine_ob_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start signal_oc_position\n");
	current_xmachine_oc_holder = oc_start_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		if(FLAME_condition_oc_signal_oc_position_start_1(current_xmachine_oc)==1)
		{

		

			i = signal_oc_position();

		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_start_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_start_state, oc_1_state);
			}
		}

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish signal_oc_position\n");

	if(FLAME_oc_position_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_oc_position)\n");
		rc = MB_SyncStart(b_oc_position);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_oc_position)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'oc_position' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start signal_ob_position\n");
	current_xmachine_ob_holder = ob_start_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		current_xmachine_ob = current_xmachine_ob_holder->agent;
		current_xmachine_ob_next_state = ob_1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_ob = current_xmachine_ob;

		if(FLAME_condition_ob_signal_ob_position_start_1(current_xmachine_ob)==1)
		{

		

			i = signal_ob_position();

		

			if(i == 1)
			{
				free_ob_agent(current_xmachine_ob_holder, ob_start_state);
			}
			else
			{
				transition_ob_agent(current_xmachine_ob_holder, ob_start_state, ob_1_state);
			}
		}

		current_xmachine_ob = NULL;

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish signal_ob_position\n");

	if(FLAME_ob_position_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_ob_position)\n");
		rc = MB_SyncStart(b_ob_position);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_ob_position)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'ob_position' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start initialize\n");
	current_xmachine_environment_holder = environment_start_state->agents;
	while(current_xmachine_environment_holder)
	{
		temp_xmachine_environment_holder = current_xmachine_environment_holder->next;
		current_xmachine_environment = current_xmachine_environment_holder->agent;
		current_xmachine_environment_next_state = environment_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_environment = current_xmachine_environment;

		if(FLAME_condition_environment_initialize_start_end(current_xmachine_environment)==1)
		{

		

			i = initialize();

		

			if(i == 1)
			{
				free_environment_agent(current_xmachine_environment_holder, environment_start_state);
			}
			else
			{
				transition_environment_agent(current_xmachine_environment_holder, environment_start_state, environment_end_state);
			}
		}

		current_xmachine_environment = NULL;

		current_xmachine_environment_holder = temp_xmachine_environment_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish initialize\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start initialize_ob\n");
	current_xmachine_ob_holder = ob_start_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		current_xmachine_ob = current_xmachine_ob_holder->agent;
		current_xmachine_ob_next_state = ob_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_ob = current_xmachine_ob;

		if(FLAME_condition_ob_initialize_ob_start_end(current_xmachine_ob)==1)
		{

		

			i = initialize_ob();

		

			if(i == 1)
			{
				free_ob_agent(current_xmachine_ob_holder, ob_start_state);
			}
			else
			{
				transition_ob_agent(current_xmachine_ob_holder, ob_start_state, ob_end_state);
			}
		}

		current_xmachine_ob = NULL;

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish initialize_ob\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start initialize_oc\n");
	current_xmachine_oc_holder = oc_start_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		if(FLAME_condition_oc_initialize_oc_start_end(current_xmachine_oc)==1)
		{

		

			i = initialize_oc();

		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_start_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_start_state, oc_end_state);
			}
		}

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish initialize_oc\n");


/* End of layer number 0 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start ob_get_older\n");
	current_xmachine_ob_holder = ob_1_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		current_xmachine_ob = current_xmachine_ob_holder->agent;
		current_xmachine_ob_next_state = ob_2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_ob = current_xmachine_ob;

		

		

			i = ob_get_older();

		

			if(i == 1)
			{
				free_ob_agent(current_xmachine_ob_holder, ob_1_state);
			}
			else
			{
				transition_ob_agent(current_xmachine_ob_holder, ob_1_state, ob_2_state);
			}
		

		current_xmachine_ob = NULL;

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish ob_get_older\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_ob_position_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_ob_position)\n");
		rc = MB_SyncComplete(b_ob_position);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_ob_position)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'ob_position' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'ob_position' board is invalid\n");
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
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_oc_position_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_oc_position)\n");
		rc = MB_SyncComplete(b_oc_position);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_oc_position)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'oc_position' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'oc_position' board is invalid\n");
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
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start create\n");
	current_xmachine_bmu_holder = bmu_start_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		current_xmachine_bmu = current_xmachine_bmu_holder->agent;
		current_xmachine_bmu_next_state = bmu_1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_bmu = current_xmachine_bmu;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = create();

		
		    rc = MB_Iterator_Delete(&i_oc_position);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'oc_position' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'oc_position' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_ob_position);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'ob_position' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'ob_position' iterator is invalid\n");
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
				free_bmu_agent(current_xmachine_bmu_holder, bmu_start_state);
			}
			else
			{
				transition_bmu_agent(current_xmachine_bmu_holder, bmu_start_state, bmu_1_state);
			}
		

		current_xmachine_bmu = NULL;

		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish create\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start check_fusions\n");
	current_xmachine_oc_holder = oc_1_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = check_fusions();

		
		    rc = MB_Iterator_Delete(&i_oc_position);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'oc_position' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'oc_position' iterator is invalid\n");
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
				free_oc_agent(current_xmachine_oc_holder, oc_1_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_1_state, oc_2_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish check_fusions\n");

	if(FLAME_fusion_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fusion)\n");
		rc = MB_SyncStart(b_fusion);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fusion)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'fusion' board\n");
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

if(FLAME_oc_position_message_board_read == 0)
{
	/*printf("%d> oc_position message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_oc_position)\n");
	rc = MB_SyncComplete(b_oc_position);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_oc_position)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'oc_position' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'oc_position' board is invalid\n");
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

if(FLAME_ob_position_message_board_read == 0)
{
	/*printf("%d> ob_position message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_ob_position)\n");
	rc = MB_SyncComplete(b_ob_position);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_ob_position)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'ob_position' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'ob_position' board is invalid\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bmu_die\n");
	current_xmachine_bmu_holder = bmu_1_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		current_xmachine_bmu = current_xmachine_bmu_holder->agent;
		current_xmachine_bmu_next_state = bmu_2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_bmu = current_xmachine_bmu;

		

		

			i = bmu_die();

		

			if(i == 1)
			{
				free_bmu_agent(current_xmachine_bmu_holder, bmu_1_state);
			}
			else
			{
				transition_bmu_agent(current_xmachine_bmu_holder, bmu_1_state, bmu_2_state);
			}
		

		current_xmachine_bmu = NULL;

		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bmu_die\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start ob_die\n");
	current_xmachine_ob_holder = ob_2_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		current_xmachine_ob = current_xmachine_ob_holder->agent;
		current_xmachine_ob_next_state = ob_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_ob = current_xmachine_ob;

		

		

			i = ob_die();

		

			if(i == 1)
			{
				free_ob_agent(current_xmachine_ob_holder, ob_2_state);
			}
			else
			{
				transition_ob_agent(current_xmachine_ob_holder, ob_2_state, ob_end_state);
			}
		

		current_xmachine_ob = NULL;

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish ob_die\n");


/* End of layer number 2 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_fusion_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fusion)\n");
		rc = MB_SyncComplete(b_fusion);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fusion)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'fusion' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fusion' board is invalid\n");
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
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start calc_fusions\n");
	current_xmachine_bmu_holder = bmu_2_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		current_xmachine_bmu = current_xmachine_bmu_holder->agent;
		current_xmachine_bmu_next_state = bmu_3_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_bmu = current_xmachine_bmu;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = calc_fusions();

		
		    rc = MB_Iterator_Delete(&i_fusion);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'fusion' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'fusion' iterator is invalid\n");
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
				free_bmu_agent(current_xmachine_bmu_holder, bmu_2_state);
			}
			else
			{
				transition_bmu_agent(current_xmachine_bmu_holder, bmu_2_state, bmu_3_state);
			}
		

		current_xmachine_bmu = NULL;

		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish calc_fusions\n");

	if(FLAME_fusion_signal_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fusion_signal)\n");
		rc = MB_SyncStart(b_fusion_signal);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fusion_signal)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'fusion_signal' board\n");
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

if(FLAME_fusion_message_board_read == 0)
{
	/*printf("%d> fusion message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fusion)\n");
	rc = MB_SyncComplete(b_fusion);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fusion)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'fusion' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fusion' board is invalid\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bmu_move\n");
	current_xmachine_bmu_holder = bmu_3_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		current_xmachine_bmu = current_xmachine_bmu_holder->agent;
		current_xmachine_bmu_next_state = bmu_4_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_bmu = current_xmachine_bmu;

		

		

			i = bmu_move();

		

			if(i == 1)
			{
				free_bmu_agent(current_xmachine_bmu_holder, bmu_3_state);
			}
			else
			{
				transition_bmu_agent(current_xmachine_bmu_holder, bmu_3_state, bmu_4_state);
			}
		

		current_xmachine_bmu = NULL;

		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bmu_move\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_fusion_signal_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fusion_signal)\n");
		rc = MB_SyncComplete(b_fusion_signal);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fusion_signal)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'fusion_signal' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fusion_signal' board is invalid\n");
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
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start fuse\n");
	current_xmachine_oc_holder = oc_2_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_3_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = fuse();

		
		    rc = MB_Iterator_Delete(&i_fusion_signal);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'fusion_signal' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'fusion_signal' iterator is invalid\n");
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
				free_oc_agent(current_xmachine_oc_holder, oc_2_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_2_state, oc_3_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish fuse\n");


/* End of layer number 4 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_fusion_signal_message_board_read == 0)
{
	/*printf("%d> fusion_signal message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fusion_signal)\n");
	rc = MB_SyncComplete(b_fusion_signal);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fusion_signal)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'fusion_signal' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fusion_signal' board is invalid\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bmu_getolder\n");
	current_xmachine_bmu_holder = bmu_4_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		current_xmachine_bmu = current_xmachine_bmu_holder->agent;
		current_xmachine_bmu_next_state = bmu_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_bmu = current_xmachine_bmu;

		

		

			i = bmu_getolder();

		

			if(i == 1)
			{
				free_bmu_agent(current_xmachine_bmu_holder, bmu_4_state);
			}
			else
			{
				transition_bmu_agent(current_xmachine_bmu_holder, bmu_4_state, bmu_end_state);
			}
		

		current_xmachine_bmu = NULL;

		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bmu_getolder\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start oc_move\n");
	current_xmachine_oc_holder = oc_3_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_4_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		

			i = oc_move();

		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_3_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_3_state, oc_4_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish oc_move\n");


/* End of layer number 5 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start oc_get_older\n");
	current_xmachine_oc_holder = oc_4_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_5_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		

			i = oc_get_older();

		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_4_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_4_state, oc_5_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish oc_get_older\n");


/* End of layer number 6 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start oc_die\n");
	current_xmachine_oc_holder = oc_5_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		current_xmachine_oc = current_xmachine_oc_holder->agent;
		current_xmachine_oc_next_state = oc_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_oc = NULL;
		current_xmachine->xmachine_ob = NULL;
		current_xmachine->xmachine_bmu = NULL;
		current_xmachine->xmachine_environment = NULL;
		current_xmachine->xmachine_oc = current_xmachine_oc;

		

		

			i = oc_die();

		

			if(i == 1)
			{
				free_oc_agent(current_xmachine_oc_holder, oc_5_state);
			}
			else
			{
				transition_oc_agent(current_xmachine_oc_holder, oc_5_state, oc_end_state);
			}
		

		current_xmachine_oc = NULL;

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish oc_die\n");


/* End of layer number 7 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */



	/*printf("oc_5_state->count = %d\n", oc_5_state->count);*/
	oc_5_state->count = 0;

	/*printf("oc_4_state->count = %d\n", oc_4_state->count);*/
	oc_4_state->count = 0;

	/*printf("oc_3_state->count = %d\n", oc_3_state->count);*/
	oc_3_state->count = 0;

	/*printf("oc_2_state->count = %d\n", oc_2_state->count);*/
	oc_2_state->count = 0;

	/*printf("oc_1_state->count = %d\n", oc_1_state->count);*/
	oc_1_state->count = 0;

	/*printf("oc_end_state->count = %d\n", oc_end_state->count);*/
	oc_end_state->count = 0;

	/*printf("oc_start_state->count = %d\n", oc_start_state->count);*/
	oc_start_state->count = 0;

	/*printf("ob_2_state->count = %d\n", ob_2_state->count);*/
	ob_2_state->count = 0;

	/*printf("ob_1_state->count = %d\n", ob_1_state->count);*/
	ob_1_state->count = 0;

	/*printf("ob_end_state->count = %d\n", ob_end_state->count);*/
	ob_end_state->count = 0;

	/*printf("ob_start_state->count = %d\n", ob_start_state->count);*/
	ob_start_state->count = 0;

	/*printf("bmu_end_state->count = %d\n", bmu_end_state->count);*/
	bmu_end_state->count = 0;

	/*printf("bmu_4_state->count = %d\n", bmu_4_state->count);*/
	bmu_4_state->count = 0;

	/*printf("bmu_3_state->count = %d\n", bmu_3_state->count);*/
	bmu_3_state->count = 0;

	/*printf("bmu_2_state->count = %d\n", bmu_2_state->count);*/
	bmu_2_state->count = 0;

	/*printf("bmu_1_state->count = %d\n", bmu_1_state->count);*/
	bmu_1_state->count = 0;

	/*printf("bmu_start_state->count = %d\n", bmu_start_state->count);*/
	bmu_start_state->count = 0;

	/*printf("environment_end_state->count = %d\n", environment_end_state->count);*/
	environment_end_state->count = 0;

	/*printf("environment_start_state->count = %d\n", environment_start_state->count);*/
	environment_start_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_oc_holder = oc_end_state->agents;
	while(current_xmachine_oc_holder)
	{
		temp_xmachine_oc_holder = current_xmachine_oc_holder->next;
		transition_oc_agent(current_xmachine_oc_holder, oc_end_state, oc_start_state);

		current_xmachine_oc_holder = temp_xmachine_oc_holder;
	}

	current_xmachine_ob_holder = ob_end_state->agents;
	while(current_xmachine_ob_holder)
	{
		temp_xmachine_ob_holder = current_xmachine_ob_holder->next;
		transition_ob_agent(current_xmachine_ob_holder, ob_end_state, ob_start_state);

		current_xmachine_ob_holder = temp_xmachine_ob_holder;
	}

	current_xmachine_bmu_holder = bmu_end_state->agents;
	while(current_xmachine_bmu_holder)
	{
		temp_xmachine_bmu_holder = current_xmachine_bmu_holder->next;
		transition_bmu_agent(current_xmachine_bmu_holder, bmu_end_state, bmu_start_state);

		current_xmachine_bmu_holder = temp_xmachine_bmu_holder;
	}

	current_xmachine_environment_holder = environment_end_state->agents;
	while(current_xmachine_environment_holder)
	{
		temp_xmachine_environment_holder = current_xmachine_environment_holder->next;
		transition_environment_agent(current_xmachine_environment_holder, environment_end_state, environment_start_state);

		current_xmachine_environment_holder = temp_xmachine_environment_holder;
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
