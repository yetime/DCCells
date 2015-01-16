/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"



/* Box filtering functions */




union pu_oc_position 
{
    m_oc_position *ptr;
    void *ptr_anon;
};

/** \fn void add_oc_position_message(celldim oc_dimension, int id, int nuclei, int bmu_scope)
 * \brief Add oc_position message by calling internal and processing.
 * \param oc_dimension Message variable.
 * \param id Message variable.
 * \param nuclei Message variable.
 * \param bmu_scope Message variable.
 */
void add_oc_position_message(celldim oc_dimension, int id, int nuclei, int bmu_scope)
{
    int rc;
	m_oc_position msg;
    
    copy_celldim(&oc_dimension, &msg.oc_dimension);
    msg.id = id;
    msg.nuclei = nuclei;
    msg.bmu_scope = bmu_scope;
    
    
    rc = MB_AddMessage(b_oc_position, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'oc_position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'oc_position' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'oc_position' board is locked\n");
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

inline static m_oc_position* getInternalMessage_oc_position(void)
{
    static m_oc_position *msg_prev = NULL;
    union pu_oc_position msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_oc_position); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'oc_position' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'oc_position' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_oc_position, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'oc_position' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'oc_position' Iterator has not been created?\n");
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

/** \fn xmachine_message_oc_position * get_first_oc_position_message()
 * \brief Get the first oc_position message in the oc_position message list.
 * \return The first message in the list.
 */
m_oc_position * get_first_oc_position_message()
{
	return getInternalMessage_oc_position();
}

/** \fn xmachine_message_oc_position * get_next_oc_position_message(xmachine_message_oc_position * current)
 * \brief Get the next oc_position message in the oc_position message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_oc_position * get_next_oc_position_message(m_oc_position * current)
{
	return getInternalMessage_oc_position();
}


/* Box filtering functions */




union pu_ob_position 
{
    m_ob_position *ptr;
    void *ptr_anon;
};

/** \fn void add_ob_position_message(celldim ob_dimension, int id)
 * \brief Add ob_position message by calling internal and processing.
 * \param ob_dimension Message variable.
 * \param id Message variable.
 */
void add_ob_position_message(celldim ob_dimension, int id)
{
    int rc;
	m_ob_position msg;
    
    copy_celldim(&ob_dimension, &msg.ob_dimension);
    msg.id = id;
    
    
    rc = MB_AddMessage(b_ob_position, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'ob_position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ob_position' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ob_position' board is locked\n");
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

inline static m_ob_position* getInternalMessage_ob_position(void)
{
    static m_ob_position *msg_prev = NULL;
    union pu_ob_position msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_ob_position); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'ob_position' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'ob_position' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_ob_position, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'ob_position' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ob_position' Iterator has not been created?\n");
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

/** \fn xmachine_message_ob_position * get_first_ob_position_message()
 * \brief Get the first ob_position message in the ob_position message list.
 * \return The first message in the list.
 */
m_ob_position * get_first_ob_position_message()
{
	return getInternalMessage_ob_position();
}

/** \fn xmachine_message_ob_position * get_next_ob_position_message(xmachine_message_ob_position * current)
 * \brief Get the next ob_position message in the ob_position message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_ob_position * get_next_ob_position_message(m_ob_position * current)
{
	return getInternalMessage_ob_position();
}


/* Box filtering functions */




union pu_fusion_signal 
{
    m_fusion_signal *ptr;
    void *ptr_anon;
};

/** \fn void add_fusion_signal_message(int id1, int f_signal, int f_bmu_id, int f_nuclei, double second_diameter)
 * \brief Add fusion_signal message by calling internal and processing.
 * \param id1 Message variable.
 * \param f_signal Message variable.
 * \param f_bmu_id Message variable.
 * \param f_nuclei Message variable.
 * \param second_diameter Message variable.
 */
void add_fusion_signal_message(int id1, int f_signal, int f_bmu_id, int f_nuclei, double second_diameter)
{
    int rc;
	m_fusion_signal msg;
    
    msg.id1 = id1;
    msg.f_signal = f_signal;
    msg.f_bmu_id = f_bmu_id;
    msg.f_nuclei = f_nuclei;
    msg.second_diameter = second_diameter;
    
    
    rc = MB_AddMessage(b_fusion_signal, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'fusion_signal' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fusion_signal' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fusion_signal' board is locked\n");
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

inline static m_fusion_signal* getInternalMessage_fusion_signal(void)
{
    static m_fusion_signal *msg_prev = NULL;
    union pu_fusion_signal msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_fusion_signal); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'fusion_signal' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'fusion_signal' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_fusion_signal, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'fusion_signal' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fusion_signal' Iterator has not been created?\n");
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

/** \fn xmachine_message_fusion_signal * get_first_fusion_signal_message()
 * \brief Get the first fusion_signal message in the fusion_signal message list.
 * \return The first message in the list.
 */
m_fusion_signal * get_first_fusion_signal_message()
{
	return getInternalMessage_fusion_signal();
}

/** \fn xmachine_message_fusion_signal * get_next_fusion_signal_message(xmachine_message_fusion_signal * current)
 * \brief Get the next fusion_signal message in the fusion_signal message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_fusion_signal * get_next_fusion_signal_message(m_fusion_signal * current)
{
	return getInternalMessage_fusion_signal();
}


/* Box filtering functions */




union pu_new_ob_position 
{
    m_new_ob_position *ptr;
    void *ptr_anon;
};

/** \fn void add_new_ob_position_message(int push_id, celldim dims)
 * \brief Add new_ob_position message by calling internal and processing.
 * \param push_id Message variable.
 * \param dims Message variable.
 */
void add_new_ob_position_message(int push_id, celldim dims)
{
    int rc;
	m_new_ob_position msg;
    
    msg.push_id = push_id;
    copy_celldim(&dims, &msg.dims);
    
    
    rc = MB_AddMessage(b_new_ob_position, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'new_ob_position' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_ob_position' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_ob_position' board is locked\n");
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

inline static m_new_ob_position* getInternalMessage_new_ob_position(void)
{
    static m_new_ob_position *msg_prev = NULL;
    union pu_new_ob_position msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_new_ob_position); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'new_ob_position' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'new_ob_position' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_new_ob_position, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'new_ob_position' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_ob_position' Iterator has not been created?\n");
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

/** \fn xmachine_message_new_ob_position * get_first_new_ob_position_message()
 * \brief Get the first new_ob_position message in the new_ob_position message list.
 * \return The first message in the list.
 */
m_new_ob_position * get_first_new_ob_position_message()
{
	return getInternalMessage_new_ob_position();
}

/** \fn xmachine_message_new_ob_position * get_next_new_ob_position_message(xmachine_message_new_ob_position * current)
 * \brief Get the next new_ob_position message in the new_ob_position message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_new_ob_position * get_next_new_ob_position_message(m_new_ob_position * current)
{
	return getInternalMessage_new_ob_position();
}

