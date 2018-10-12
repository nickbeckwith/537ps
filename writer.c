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
#include "main.h"

/**
 * Writes lines in queue to stdout
 * @param args is a pointer to a readWriteParams struct
 */
void * writer(void *args) {
    int count = 0;          // counts number of strings passed through
    char * str;
    Queue *q = ((struct readWriteParams*) args)->q;
    str = dequeueString(q);
    while(str != NULL) {
        fprintf(stdout, "%s", str);
        count++;
        free(str);
        str = dequeueString(q);
    }
    fprintf(stdout, "Number of Strings Processed: %d\n", count);
}
