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
 * NAME: Richard Onyett 
 * EMAIL: 
 *
 * PURPOSE: 
 * Header file for simple static Queue
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
#ifndef __S_QUEUE_H__
#define __S_QUEUE_H__

/*
******************************************************************************
Private Constants
******************************************************************************
*/
#define MAX_QUEUE_SIZE           4
#define MAX_NUMBER_OF_QUEUES     4

#define semaphore_t              int /* For now */

/*
******************************************************************************
Private Types
******************************************************************************
*/
typedef enum
{
  q_created,
  q_unused ,
  q_recieve,
  q_respond,
  q_send_no_wait,
  q_send_to_front,
  q_send_wait,
  q_delete 
} OSMsgq_status_t;

typedef struct                    /* Generic Message bucket */
{
  int MsgSize;                    /* Size of this message   */  
  void *pMsg;                     /* Make fixed size        */
  void *pNextMsg;
} message_t;

typedef struct internal_OSMsgq_t  /* Store all Msg Q details*/
{
  bool MsgqUsed;                  /* Indicate Msg is used   */
  int mId;
  int  tTask;              /* Task requesting        */
  int  event_flag;               /* Event to trigger on Q  */
  OSMsgq_status_t qStatus;        /* State of Messaging     */
  int qCount; 
  int qMsgCount;      
  int qCurrent;
  int qHighWaterMark;
  message_t *pMsgQ;               /* Created Q bucket       */
  message_t *pMsgQHead;
  message_t *pMsgQTail;
  semaphore_t qRecvSem;
  semaphore_t qXmitSem;        
} Queue_t;

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

/*
******************************************************************************
Global variables
******************************************************************************
*/
void qInit   ( Queue_t *qp);
void qClear  ( Queue_t *qp);
bool qEnQueue( Queue_t *qp, QNode_t *np );
bool qDeQueue( Queue_t *qp, QNode_t *np );
void qDump   ( Queue_t *pq);

#endif /* __S_QUEUE_H__ */

