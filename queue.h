/*****************************************************
 * FILE NAME queue.h
 *
 * PURPOSE //TODO
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#ifndef P2_QUEUE_H
#define P2_QUEUE_H

#include <sys/types.h>

extern int const MAX_STR_SIZE;

typedef struct __queue_t {
	int head, tail;
	int size;
	int capacity;
	char **arr;
	pthread_cond_t empty, full;
	pthread_mutex_t lock;
	// non essentials
	int enqueueCount;
	int dequeueCount;
	int enqueueBlockCount;
	int dequeueBlockCount;
} Queue;

Queue * createStringQueue(int);
void enqueueString(Queue*, char*);
char * dequeueString(Queue*);
void printQueueStats(Queue*);
void freeQueue(Queue*);
#endif //P2_QUEUE_H
