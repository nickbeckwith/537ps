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
#include "queue.h"


int const DEPTH = 10;            // describes depth of queue

int main(int argc, char * argv[]) {
    char *str = malloc(255 * sizeof(char));
    while (fgets(str, 255, stdin) != NULL) {
        fprintf(stdout, "%s", str);
    }

    /*
    // create three queues
    Queue *queue1 = createStringQueue(DEPTH);
    Queue *queue2 = createStringQueue(DEPTH);
    Queue *queue3 = createStringQueue(DEPTH);

    // create three threads
    pthread_t thread1, thread2, thread3;
    int proc1, proc2, proc3;
     */
}

