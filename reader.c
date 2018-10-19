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
    char *buffer = malloc(MAX_STR_SIZE * sizeof(char));
    int fitsBuffer;
    int fgetcOut;
    // for each input line, clip part that exceeds buffer size and place in queue
    while(1) {
        if (fgets(buffer, MAX_STR_SIZE, stdin) != NULL) {
            // check if the line fits into our buffer
            fitsBuffer = 0;
            for (int i = 0; i < MAX_STR_SIZE; i++) {
                if (buffer[i] == '\n') {        // if there's a new line, we're good
                    fitsBuffer = 1;
                    break;
                }
            }
            if (!fitsBuffer) {
                fprintf(stderr, "Error: stdin line too long. Max size: %d\n", MAX_STR_SIZE);
                // remove the rest of the line
                while ((fgetcOut = fgetc(stdin)) != '\n' && fgetcOut != EOF);
                // make sure we didn't consume EOF
                if (fgetcOut == EOF) {
                    if (feof(stdin)) {
                        enqueueString(q, NULL);
                        break;              // if end of file, get out of loop and terminate
                    } else {
                        fprintf(stdout, "Fatal error in reader.c/reader\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else {
                enqueueString(q, buffer);
            }
        }
        else if (feof(stdin)) {
            enqueueString(q, NULL);
            break;              // if end of file, get out of loop and terminate
        }
        else {
            fprintf(stdout, "Fatal error in reader.c/reader\n");
            exit(EXIT_FAILURE);
        }
    }
	pthread_exit(NULL);
}
