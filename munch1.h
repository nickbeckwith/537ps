/*****************************************************
 * FILE NAME munch1.h
 *
 * PURPOSE Munch1 will scan the line and replace each blank
 * character with an asterisk ("*") character. It will then
 * pass the line to thread Munch2 through another queue of
 * character strings.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#ifndef P2_MUNCH1_H
#define P2_MUNCH1_H

#include "queue.h"

void munch1(Queue *q1, Queue *q2);

#endif //P2_MUNCH1_H
