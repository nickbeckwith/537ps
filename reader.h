/*****************************************************
 * FILE NAME reader.h
 *
 * PURPOSE read from standard input, one line at a time.
 * Reader will take the each line of the input and pass it
 * to thread Munch1 though a queue of character strings.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#ifndef P2_READER_H
#define P2_READER_H

#include "queue.h"

void reader(Queue *);
#endif //P2_READER_H
