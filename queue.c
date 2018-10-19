#include <stdio.h>
#include <malloc.h>
#include <pthread.h>
#include <stdlib.h>
#include "queue.h"


int const MAX_STR_SIZE = 20;

Queue * createStringQueue(int size) {
	Queue *q;
	if ((q = (Queue *) malloc(sizeof(Queue))) == NULL) {
		fprintf(stderr, "Error: Unable to malloc in createStringQueue\n");
		exit(EXIT_FAILURE);
	}
	q->size = 0;
	q->capacity = size;
	q->head = 0;
	q->tail = q->capacity - 1;
	if ((q->arr = (char **) malloc(size * sizeof(char *))) == NULL) {
		fprintf(stderr, "Error: Unable to malloc in createStringQueue\n");
		exit(EXIT_FAILURE);
	}
	// initialize synchronization tools
	if ((pthread_mutex_init(&q->lock, NULL)) != 0) {
		fprintf(stderr, "Error: Unable to init mutex\n");
		exit(EXIT_FAILURE);
	}
	if ((pthread_cond_init(&q->empty, NULL)) != 0) {
		fprintf(stderr, "Error: Unable to init cond\n");
		exit(EXIT_FAILURE);
	}
	if ((pthread_cond_init(&q->full, NULL)) != 0) {
		fprintf(stderr, "Error: Unable to init cond\n");
		exit(EXIT_FAILURE);
	}
	// non essential initialization
	q->enqueueCount = 0;
	q->dequeueCount = 0;
	q->enqueueBlockCount = 0;
	q->dequeueBlockCount = 0;
	return q;
}

void enqueueString(Queue *q, char *string) {
	pthread_mutex_lock(&q->lock);
	while (q->size == q->capacity) {
		q->enqueueBlockCount++;
		pthread_cond_wait(&q->empty, &q->lock);	
	}
	// have to make it ciclic somehow. Mod does this.
	q->tail = (q->tail + 1) % q->capacity;
	q->arr[q->tail] = string;
	q->size++;
	q->enqueueCount++;
	pthread_cond_signal(&q->full);
	pthread_mutex_unlock(&q->lock);
}

char * dequeueString(Queue *q) {
	pthread_mutex_lock(&q->lock);
	while (q->size == 0) {
		q->dequeueBlockCount++;
		pthread_cond_wait(&q->full, &q->lock);
	}
	char *str = q->arr[q->head];
	q->head = (q->head + 1) % q->capacity;
	q->size--;
	q->dequeueCount++;
	pthread_cond_signal(&q->empty);
	pthread_mutex_unlock(&q->lock);
	return str;
}

void printQueueStats(Queue *q) {
    fprintf(stderr, "Enqueue Count: %d\n"
                    "Dequeue Count: %d\n"
                    "Enqueue Block Count: %d\n"
                    "Dequeue Block Count %d\n",
                    q->enqueueCount, q->dequeueCount,
                    q->enqueueBlockCount, q->dequeueBlockCount);
}

void freeQueue(Queue *q) {
	free(q->arr);
	if (pthread_cond_destroy(&q->empty) != 0) {
		fprintf(stderr, "Error: Unable to destroy empty conditional variable\n");
		exit(EXIT_FAILURE);
	}
	if (pthread_cond_destroy(&q->full) != 0) {
		fprintf(stderr, "Error: Unable to destroy full conditional variable\n");
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_destroy(&q->lock) != 0) {
		fprintf(stderr, "Error: Unable to destroy mutex\n");
		exit(EXIT_FAILURE);
	}
	free(q);
}
