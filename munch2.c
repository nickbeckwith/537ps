/*****************************************************
 * FILE NAME munch2.c
 *
 * PURPOSE Munch2 will scan the line and convert all
 * lower case letters to upper case (e.g., convert "a" to "A").
 * It will then pass the line to thread Writer though yet
 * another queue of character strings.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#include <stdio.h>
#include "queue.h"
#include "munch2.h"

/**
 * Changes all lower case letters to uppercase
 * @param q1 queue to receive data
 * @param q2 queue to send data
 */
void munch2(Queue *q1, Queue *q2) {
    char *str;
    str = dequeueString(q1);
    char *str_cpy;
    while (fgets(str, 255, stdin) != NULL) {
        str_cpy = str;
        while (*str_cpy != '\0') {
            if (islower(*str_cpy)) {
                *str_cpy = (char) toupper(*str_cpy);
            }
            str_cpy++;
        }
        fprintf(stdout, "%s", str);
    }
}