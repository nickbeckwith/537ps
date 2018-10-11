/*****************************************************
 * FILE NAME queue.h
 *
 * PURPOSE //TODO
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#ifndef P2_QUEUE_H
#define P2_QUEUE_H

int const extern MAX_STR_SIZE;

typedef struct Queues {
    int enqueueCount;
    int dequeueCount;
    int enqueueBlockCount;
    int dequeueBlockCount;
} Queue;

Queue * createStringQueue(int);
void enqueueString(Queue*, char*);
char * dequeueString(Queue*);
void printQueueStats(Queue*);

#endif //P2_QUEUE_H
