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
#include "main.h"

/**
 * Changes all lower case letters to uppercase
 * @param args a munchParams struct
 */
void * munch2(void *args) {
    struct munchParams * params = args;
    Queue *q1 = params->q1;
    Queue *q2 = params->q2;
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