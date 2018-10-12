/*****************************************************
 * FILE NAME writer.c
 *
 * PURPOSE Writer will write the line to standard output.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#include <stdio.h>
#include <malloc.h>
#include "queue.h"

/**
 * Writes lines in queue to stdout
 * @param q a queue
 */
void writer(Queue *q) {
    char * str;
    str = dequeueString(q);
    while(str != NULL) {
        fprintf(stdout, "%s", str);
        free(str);
        str = dequeueString(q);
    }
}
