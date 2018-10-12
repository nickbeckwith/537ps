//
// Created by nick on 10/10/18.
//

#ifndef P2_MAIN_H
#define P2_MAIN_H

#include "queue.h"

// Contains parameters for either munch function
struct munchParams {
    Queue *q1;
    Queue *q2;
};

// Contains the paramater for either reader or writer
struct readWriteParams {
    Queue *q;
};

#endif //P2_MAIN_H
