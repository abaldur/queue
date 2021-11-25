#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

#define CIRC_BBUF_DEF(x,y)                \
    void * x##_data_space[y];            \
    circ_bbuf_t x = {                     \
        .buffer = x##_data_space,         \
        .head = 0,                        \
        .tail = 0,                        \
        .maxlen = y                       \
    }

typedef struct {
    void ** const buffer;
    int head;
    int tail;
    const int maxlen;
} circ_bbuf_t;

int circ_bbuf_push(circ_bbuf_t *c, void *data);
int circ_bbuf_pop(circ_bbuf_t *c, void **data);

#endif