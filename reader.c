/*****************************************************
 * FILE NAME reader.c
 *
 * PURPOSE read from standard input, one line at a time.
 * Reader will take the each line of the input and pass it
 * to thread Munch1 though a queue of character strings.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "reader.h"
#include "main.h"

/**
 * Reads in lines that are only MAX_STR_SIZE long and rejects
 * others. Includes new line.
 *
 * @param args readWriteParam struct
 */
void * reader(void *args) {
    Queue *q = ((struct readWriteParams*) args)->q;
    char * buffer;
    int lineFinished;
    int c;
    // for each input line, clip part that exceeds buffer size and place in queue
    while(1) {
        lineFinished = 0;
        buffer = malloc(sizeof(char) * MAX_STR_SIZE);
        for (int i = 0; i < MAX_STR_SIZE - 1; i++) {
            c = getc(stdin);
            if (c == '\n') {                            // read until \n or EOF
                buffer[i] = '\0';
                enqueueString(q, buffer);
                lineFinished = 1;
                break;
            } else if (c == EOF) {
                if (feof(stdin)) {
                    buffer[i] = '\0';
                    if (buffer[0] != '\0') {            // if this isn't an empty string, (no new line)
                        enqueueString(q, buffer);
                    }
                    enqueueString(q, NULL);
                    pthread_exit(NULL);
                } else {
                    fprintf(stderr, "Fatal Error: something went wrong in fgetc");
                    exit(EXIT_FAILURE);
                }
            } else {
                buffer[i] = (char) c;
            }
        }
        if (lineFinished == 0) {
            fprintf(stderr, "Error: stdin line too long. Max size: %d\n", MAX_STR_SIZE);
            while(1) {
                c = fgetc(stdin);
                if (c == '\n') {
                    break;
                } else if (c == EOF) {
                    if (feof(stdin)) {
                        enqueueString(q, NULL);
                        pthread_exit(NULL);
                    } else {
                        fprintf(stderr, "Fatal Error: something went wrong in fgetc");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }
}
