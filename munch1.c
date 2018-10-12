/*****************************************************
 * FILE NAME munch1.c
 *
 * PURPOSE Munch1 will scan the line and replace each blank
 * character with an asterisk ("*") character. It will then
 * pass the line to thread Munch2 through another queue of
 * character strings.
 *
 * AUTHOR: Nicholas Beckwith, Matthew Strimaitis
 *****************************************************/

#include <stdlib.h>
#include <strings.h>
#include "munch1.h"
#include "main.h"


/**
 * Replaces first instance of string
 *
 * @param str a pointer to the string wanting to be replaced
 * @return a pointer to the last
 */
char * replaceSpace(char *str) {
    char *tail;
    int i;
    if (str == NULL) {
        return NULL;
    }
    else {
        tail = index(str, ' ');
        if (tail != NULL) {
            *tail = '*';
            return (replaceSpace(tail));
        }
        else {
            return (NULL);
        }
    }
}

/**
 * Replaces all spaces with '*' until
 * we receive a null char
 *
 * @param args munchParams struct
 */
void * munch1(void *args) {
    struct munchParams * params = args;
    Queue *q1 = params->q1;
    Queue *q2 = params->q2;
    char *str;
    str = dequeueString(q1);
    while (str != NULL) {
        enqueueString(q2, replaceSpace(str));
        str = dequeueString(q1);
    }
}


