/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"



/* Box filtering functions */




union pu_pointsource 
{
    m_pointsource *ptr;
    void *ptr_anon;
};

/** \fn void add_pointsource_message(ps location)
 * \brief Add pointsource message by calling internal and processing.
 * \param location Message variable.
 */
void add_pointsource_message(ps location)
{
    int rc;
	m_pointsource msg;
    
    copy_ps(&location, &msg.location);
    
    
    rc = MB_AddMessage(b_pointsource, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'pointsource' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pointsource' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pointsource' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_pointsource* getInternalMessage_pointsource(void)
{
    static m_pointsource *msg_prev = NULL;
    union pu_pointsource msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_pointsource); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'pointsource' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'pointsource' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_pointsource, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'pointsource' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pointsource' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_pointsource * get_first_pointsource_message()
 * \brief Get the first pointsource message in the pointsource message list.
 * \return The first message in the list.
 */
m_pointsource * get_first_pointsource_message()
{
	return getInternalMessage_pointsource();
}

/** \fn xmachine_message_pointsource * get_next_pointsource_message(xmachine_message_pointsource * current)
 * \brief Get the next pointsource message in the pointsource message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_pointsource * get_next_pointsource_message(m_pointsource * current)
{
	return getInternalMessage_pointsource();
}


/* Box filtering functions */




union pu_position 
{
    m_position *ptr;
    void *ptr_anon;
};

/** \fn void add_position_message(gridcell geo, int celltype)
 * \brief Add position message by calling internal and processing.
 * \param geo Message variable.
 * \param celltype Message variable.
 */
void add_position_message(gridcell geo, int celltype)
{
    int rc;
	m_position msg;
    
    copy_gridcell(&geo, &msg.geo);
    msg.celltype = celltype;
    
    
    rc = MB_AddMessage(b_position, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'position' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'position' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_position* getInternalMessage_position(void)
{
    static m_position *msg_prev = NULL;
    union pu_position msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_position); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'position' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'position' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_position, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'position' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'position' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_position * get_first_position_message()
 * \brief Get the first position message in the position message list.
 * \return The first message in the list.
 */
m_position * get_first_position_message()
{
	return getInternalMessage_position();
}

/** \fn xmachine_message_position * get_next_position_message(xmachine_message_position * current)
 * \brief Get the next position message in the position message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_position * get_next_position_message(m_position * current)
{
	return getInternalMessage_position();
}

