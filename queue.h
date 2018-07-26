/*
 *****************************************************************************
 *! \file 
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
 * NAME: 
 * EMAIL: 
 *
 * PURPOSE: 
 * Header file for simple Queue
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
#ifndef __QUEUE_H__
#define __QUEUE_H__

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

/**
 * \struct QNode
 * \brief  Data structure to hold the details about a Q element 
 */
typedef struct QNode { 
  QNode *pNext;      
  int value;
} QNode_t;

typedef struct Queue {
  QNode *pFront;
  QNode *pTail;
  int qNodeCount;
} Queue_t;

/*
******************************************************************************
Private Macros
******************************************************************************
*/

Queue_t *qCreate(void);
QNode_t *qNewNode(int value);
QNode_t *qDeQueue(Queue_t *qp);
void    qEnQueue(Queue_t *qp, int value);
void    qDump (Queue_t *pQueue);

#endif /* __QUEUE_H__ */

