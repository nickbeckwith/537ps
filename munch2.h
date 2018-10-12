/*****************************************************
 * FILE NAME munch2.h
 *
 * PURPOSE Munch2 will scan the line and convert all
 * lower case letters to upper case (e.g., convert "a" to "A").
 * It will then pass the line to thread Writer though yet
 * another queue of character strings.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#include <ctype.h>
#include "queue.h"

#ifndef P2_MUNCH2_H
#define P2_MUNCH2_H

void munch2(Queue *q1, Queue *q2);

#endif //P2_MUNCH2_H
