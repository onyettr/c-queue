/*
 *****************************************************************************
 * 
 * MODULE: C Programming Examples
 *
 * $Header: $
 * $Archive:$
 * 
 * $Workfile: $
 *
 * $Author: Onyettr $
 *
 * NAME: Richard Onyett 
 * EMAIL: 
 *
 * PURPOSE: Simple Static message
 *
 * 
 * $Revision:$
 * $History: $
 *
 ***************************************************************************** 
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include "squeue.h"

static Queue_t osmsgq_list[MAX_OS_QUEUES];

static bool isEmpty(Queue_t *pq);
static bool isFull (Queue_t *pq);

/*
 -- --------------------------------------------------------------
 -- static int isEmpty(stack_t *pStack)
 -- --------------------------------------------------------------
*/
static bool isEmpty(Queue_t *pq) {
  return pq->qCount == -1 ? true : false;
}


/*
 -- --------------------------------------------------------------
 -- --------------------------------------------------------------
*/
static bool isFull (Queue_t *pq) {
  return ((pq->qTail - MAX_QUEUE_SIZE) == pq->qFront);
}

void qInit( Queue_t *qp) {
  message_t *pMsgQ;

  /*
   * Pull out a Message record for this ID
   */
  pMsg  = (OSMsgq_t  *)&osmsgq_list[msg_q_id];

  /*
   * Defend against the Application
   */
#if 0
  /*
   * Get the Task Context for the calling task, we
   * will store this in the MessageQ record for 
   * later use.
   */
  if ( !GetCurrentTaskContext(&pTask) )
  {
    return OS_INVALID_TASK_ID;
  }

  /*
   * Invalid events as nothing to wait on
   */
  if (event_flag == 0)
  {
    return OS_INVALID_EVENTS;
  }
#endif  
  /*
   * Check if this Q is not already used up.
   */
  if (pMsg->MsgqUsed == true) {
    printf ("OS_ID_EXISTS - Q already used\n");
  }

  //  semaphore_wait   ( &__OSMsgq );  /* Go critical */

  /*
   * First allocate a Queue 
   * TODO: Make this static allocation
   */
#if 0  
  pMsgQ = (message_t *)memory_allocate( system_partition,
					OS_MAX_QUEUE_SIZE * sizeof(message_t));

  if ( pMsgQ == NULL )
  {
    return OS_NO_MEMORY;
  }
#endif
  pMsg->mId       = msg_q_id;
  pMsg->MsgqUsed  = true;
  pMsg->event_flag= event_flag;
  pMsg->pMsgQ     = pMsgQ;
  pMsg->pMsgQHead = pMsgQ;
  pMsg->pMsgQTail = pMsgQ;
  //pMsg->tTask     = pTask->tId;
  pMsg->qStatus   = q_created;
  pMsg->qCount    = 1;
  pMsg->qMsgCount = 0;
  pMsg->qHighWaterMark = 0;
  //  semaphore_init_fifo_timeout ( &pMsg->qXmitSem, OS_MAX_QUEUE_SIZE ); 
  //  semaphore_init_fifo_timeout ( &pMsg->qRecvSem, 0 );
    
  /*
   * setup the circular list
   */
  for ( i = 0; i < OS_MAX_QUEUE_SIZE; ++i ) {
    pMsgQ[i].pNextMsg = &pMsgQ[(i + 1) % OS_MAX_QUEUE_SIZE];
  }

  //  semaphore_signal ( &__OSMsgq );
}

void qClear( Queue_t *qp) {
}

bool qDeQueue(Queue_t *qp, QNode_t *np ) {

  if ( isEmpty(qp)) {            /* First entry in the Queue */
    printf("qDeQueue: Empty\n");

    return false;
  }


  return true;
}

bool qEnQueue(Queue_t *qp, QNode_t *np ) {


  return true;
}

/*
 -- --------------------------------------------------------------
 -- --------------------------------------------------------------
*/
void qDump (Queue_t *pq) {
  int i = 0;
  
}
