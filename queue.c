#include <stdio.h>
#include <malloc.h>
#include "queue.h"

int const MAX_STR_SIZE = 20;


Queue * createStringQueue(int size) {
    return malloc(sizeof(char *) * size);
}

void enqueueString(Queue *q, char *string) {

}

char * dequeueString(Queue *q) {

}

void printQueueStats(Queue *q) {
    fprintf(stderr, "Enqueue Count: %d\n"
                    "Dequeue Count: %d\n"
                    "Enqueue Block Count: %d\n"
                    "Dequeue Block Count %d\n",
                    q->enqueueCount, q->dequeueCount,
                    q->enqueueBlockCount, q->dequeueBlockCount);
}