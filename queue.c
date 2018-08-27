/**
 *****************************************************************************
 * MODULE: C Programming Examples
 *
 * @author onyettr 
 * @file   queue.c
 *
 * PURPOSE: Simple Queue implementation
 ***************************************************************************** 
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "trap.h"

/*
******************************************************************************
Private Constants
******************************************************************************
*/

/*
******************************************************************************
Private Types
******************************************************************************
*/

/*
******************************************************************************
Private variables (static)
******************************************************************************
*/

/*
******************************************************************************
Private Macros
******************************************************************************
*/

/*
******************************************************************************
Global variables
******************************************************************************
*/

/*
******************************************************************************
Exported Global variables
******************************************************************************
*/
  
/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/
static bool isEmpty(Queue_t *pq);
Queue_t *qCreate(void);
QNode_t *qNewNode(int value);
QNode_t *qDeQueue(Queue_t *qp);
void    qEnQueue(Queue_t *qp, int value);
void    qDump (Queue_t *pq);

/**
 * @brief             test if queue is empty
 *
 * @function          static int isEmpty(stack_t *pStack)
 *
 * @param[in]         Queue *pg - Queue pointer
 *
 * @return            BOOL        TRUE if empty, false otherwise
 */
static bool isEmpty(Queue_t *pq) {
  return pq->pTail == NULL ? true : false;
}

/**
 * @brief             Create a new Queue
 *
 * @function          Queue_t *qCreate(void) - Create a Queue
 *
 * @param[in]         None
 *
 * @return            Queue_t - pointer to new Queue
 */
Queue_t *qCreate(void) {
  Queue_t *q = (Queue_t*)NULL;

  q = (Queue_t*)malloc(sizeof(Queue_t));
  if ( q != NULL) {
    q->pFront = NULL;
    q->pTail  = NULL;
    q->qNodeCount = 0;
  }

  return q;
}

/**
 * @brief             Create a new Node
 *
 * @function          QNode_t qNewNode(int value)
 *
 * @param[in]         int Value - for storage
 *
 * @return            QNode_t * Pointer to a new node
 */
QNode_t *qNewNode(int value) {
  QNode_t *p = NULL;

  p = (QNode_t *)malloc(sizeof(QNode_t));
  if ( p != NULL ) {
    p->value = value;
    p->pNext = NULL;
  }

  return p;
}

/**
 * @brief             Pull a node from a Queue
 *
 * @function          QNode_t *qDeQueue(Queue_t *gp)
 *
 * @param[in]         Queue_t *gp   Queue from which node is returned
 *
 * @return            QNode_t * Pointer to the node
 */
QNode_t *qDeQueue(Queue_t *qp) {
  QNode_t *pn = NULL;

  /* TODO Implement */
  
  return pn;
}

/**
 * @brief             Add a node to a Queue
 *
 * @function          void    qEnQueue(Queue_t *qp, int value)
 *
 * @param[in]         Queue_t *gp        Queue to add node
 *
 * @param[in]         int      value     "data" to add to the node
 *
 * @return            None
 *
 * @note
 */
void    qEnQueue(Queue_t *qp, int value) {
  QNode_t *np = NULL;

  np = qNewNode (value);
  if ( isEmpty(qp)) {      /* First entry in the Queue */
    qp->pFront = qp->pTail = np;
  } else {
    qp->pTail->pNext = np;
    qp->pTail = np;
  }

  qp->qNodeCount++;

  return;
}

/**
 * @brief             Dump put the Queue details
 *
 * @function          void qDump (Queue_t *pq) 
 *
 * @param[in]         Queue_t *gp        Queue to print
 *
 * @return            None
 *
 * @note
 */
void qDump (Queue_t *pq) {
  int i = 0;
  QNode_t *p = NULL;
  
  if (isEmpty(pq)) {
    printf ("empty - nothing to display\n");

    return;
  }

  printf("**** Queue ****\n");
  printf("Queue      [%p]\n", (void *)pq);
  printf("Node count [%d]\n", pq->qNodeCount);

  p = pq->pFront;
  while ( p ) {
    printf("[%d] %d\n", i, p->value);
    p = p->pNext;
    i++;
  }
}
