# Simple makefile for C Queue
#
CC    		= g++
LINK  		= g++
DEBUG 		= -g

# Gcov covreage
#PFLAGS=-fprofile-arcs -ftest-coverage

CFLAGS		= -c -Wall -pedantic $(PFLAGS)
LFLAGS		= $(PFLAGS)

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness

# Code checking
CODE_CHECK	= splint
CODE_CHECK_ARGS	= -showfunc 

OBJS   		= main.o queue.o trap.o test01.o
SQOBJS 		= smain.o staticq.o testsq.o

#
# Build targets
#
all:	queue.exe splint-it

queue.exe:	$(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) -o queue.exe

main.o:		main.c
	$(CC) $(CFLAGS) $(DEBUG) main.c -o main.o
queue.o:	queue.c
	$(CC) $(CFLAGS) $(DEBUG) queue.c -o queue.o
trap.o:		trap.c
	$(CC) $(CFLAGS) $(DEBUG) trap.c -o trap.o
test01.o:	test01.c
	$(CC) $(CFLAGS) $(DEBUG) test01.c -o test01.o

squeue.exe:	$(SQOBJS)
	$(LINK) $(LFLAGS) $(SQOBJS) -o squeue.exe

smain.o:	smain.c
	$(CC) $(CFLAGS) $(DEBUG) smain.c -o smain.o
staticq.o:	staticq.c
	$(CC) $(CFLAGS) $(DEBUG) staticq.c -o staticq.o
testsq.o:	testsq.c
	$(CC) $(CFLAGS) $(DEBUG) testsq.c -o testsq.o

splint-it:
	$(CODE_CHECK) $(CODE_CHECK_ARGS) main.c  
	$(CODE_CHECK) $(CODE_CHECK_ARGS) trap.c   
	$(CODE_CHECK) $(CODE_CHECK_ARGS) test01.c
#	$(CODE_CHECK) $(CODE_CHECK_ARGS) queue.c     

clean:
	rm -f queue.exe
	rm -f squeue.exe
	rm -f queue.o
	rm -f test01.o
	rm -f main.o
	rm -f trap.o
	rm -f testsq.o
	rm -f staticq.o
	rm -f smain.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f core

#
# Fin
#

