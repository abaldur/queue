#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t *storage;
    size_t total_space;
    int head;
    int tail;
    int maxlen;
} queue_t;


void queue_init(queue_t *queue, void *storage_buf, size_t storage_len);

// int circ_bbuf_push(circ_bbuf_t *c, void *data);
// int circ_bbuf_pop(circ_bbuf_t *c, void **data);



#endif