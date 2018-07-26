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
 * NAME: Richard Onyett (STMicroelectronics,San Jose)
 * EMAIL: richard.onyett@st.com
 *
 * PURPOSE: Test harness for Static Q.
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
#include "squeue.h"

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

int test01 ( void ) {
  Queue_t qp;

  printf("\ntest01 - create queue\n" );

  qInit(&qp);  
  printf("test01 - qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);  

  return 0;
}

int test02 ( void ) {
  Queue_t qp;
  QNode_t np;
  
  printf("\ntest02 - enqueue\n" );

  qInit(&qp);  
  printf("test02 - qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);  

  np.value = 101;
  qEnQueue(&qp, &np);
  printf("test02 - after Enq, qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);      

  np.value = 102;  
  qEnQueue(&qp, &np);
  printf("test02 - after Enq, qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);      

  np.value = 103;
  qEnQueue(&qp, &np);
  printf("test02 - after Enq, qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);      

  qDump (&qp);
  
  return 0;
}

int test03 ( void ) {
  Queue_t qp;
  QNode_t np;
  
  printf("\ntest03 - deaqueue\n" );

  qInit(&qp);  
  printf("test03 - qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);  

  np.value = 101;
  qEnQueue(&qp, &np);
  printf("test03 - after Enq, qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);      

  np.value = 102;
  qEnQueue(&qp, &np);
  printf("test03 - after Enq, qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);      

  np.value = 103;  
  qEnQueue(&qp, &np);
  printf("test03 - after Enq, qNodeCount %d, qTail %d, qFront %d\n", qp.qNodeCount, qp.qTail, qp.qFront);      

  qDump(&qp);
  
  qDeQueue(&qp, &np);
  printf("test03 - after Deq, node %d, qNodeCount %d, qTail %d, qFront %d\n",
	 np.value, 
	 qp.qNodeCount, qp.qTail, qp.qFront);        

  qDump(&qp);  
  qDeQueue(&qp, &np);
  printf("deq np addr %x\n", np);
  printf("test03 - after Deq, node %d, qNodeCount %d, qTail %d, qFront %d\n",
	 np.value, 
	 qp.qNodeCount, qp.qTail, qp.qFront);        

  qDump(&qp);  
  qDeQueue(&qp, &np);
  printf("deq np addr %x\n", np);  
  printf("test03 - after Deq, node %d, qNodeCount %d, qTail %d, qFront %d\n",
	 np.value, 
	 qp.qNodeCount, qp.qTail, qp.qFront);        

  qDump(&qp);
  qDeQueue(&qp, &np);
  printf("deq np addr %x\n", np);  
  printf("test03 - after Deq, node %d, qNodeCount %d, qTail %d, qFront %d\n",
	 np.value, 
	 qp.qNodeCount, qp.qTail, qp.qFront);        
  
  return 0;
}

int test_run ( void ) {
  int error_code = 0;

  error_code = test01();    /* Run one of the tests */
  error_code = test02();    /* Run one of the tests */
  error_code = test03();    /* Run one of the tests */
  
  return error_code;
}

//
// Fin
//
  
