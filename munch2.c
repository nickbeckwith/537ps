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

#include <wchar.h>
#include "queue.h"
#include "munch2.h"

void munch2(Queue *q1, Queue *q2) {
    char *str;
    str = dequeueString(q1);
    while (str != NULL) {
        while (*str != '\0') {
            if (islower(*str)) {
                *str = (char) toupper(*str);
            }
            str++;
        }
        str = dequeueString(q1);
    }
}
