/*****************************************************
 * FILE NAME main.c
 *
 * other SRC: main.h, monitor.{c,h}, munch{1,2}.{c,h}
 * queue.{c,h}, reader.{c,h}, writer.{c,h}
 *
 * other files: README, makefile
 *
 * PURPOSE //TODO
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <asm/errno.h>
#include "writer.h"
#include "main.h"
#include "munch1.h"
#include "munch2.h"
#include "reader.h"


int const DEPTH = 10;            // describes depth of queue

/**
 * As specified in p_thread man but checks for errors on creation
 *
 * @param thread
 * @param func
 * @param arg
 * @return
 */
void safelyCreateThread(pthread_t *thread, void *(*start_routine) (void *), void *arg) {
    int err = pthread_create(thread, NULL, start_routine, arg);
    if (err  != 0) {
        if (err == EAGAIN) {
            fprintf(stderr, "ERROR: Insufficient resources to create another thread\n");
            exit(EXIT_FAILURE);
        }
        else {
            fprintf(stderr, "ERROR: Unable to create another thread\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char * argv[]) {
	(void)argc;
	(void)argv;
    // create three queues
    Queue *q1 = createStringQueue(DEPTH);
    Queue *q2 = createStringQueue(DEPTH);
    Queue *q3 = createStringQueue(DEPTH);

    // declare four threads
    pthread_t thread1, thread2, thread3, thread4;

    // Create four heap locations for arguments
    struct readWriteParams *args1 = malloc(sizeof(struct readWriteParams));
    struct munchParams *args2 = malloc(sizeof(struct munchParams));
    struct munchParams *args3 = malloc(sizeof(struct munchParams));
    struct readWriteParams *args4 = malloc(sizeof(struct readWriteParams));

    // Initialize all parameters
    *args1 = (struct readWriteParams) {q1};
    *args2 = (struct munchParams) {q1, q2};
    *args3 = (struct munchParams) {q2, q3};
    *args4 = (struct readWriteParams) {q3};

    pthread_create(&thread1, NULL, &reader, args1);
    // create four threads
    safelyCreateThread(&thread1, &reader, args1);
    safelyCreateThread(&thread2, &munch1, args2);
    safelyCreateThread(&thread3, &munch2, args3);
    safelyCreateThread(&thread4, &writer, args4);

    // wait for the fourth thread which must finish last
    pthread_join(thread4, NULL);

    // Print queue stats
    fprintf(stderr, "\nQueue 1 Statistics:\n");
    printQueueStats(q1);
    fprintf(stderr, "Queue 2 Statistics:\n");
    printQueueStats(q2);
    fprintf(stderr, "Queue 3 Statistics:\n");
    printQueueStats(q3);

    // free queues
    free(q1);
    free(q2);
    free(q3);


}

