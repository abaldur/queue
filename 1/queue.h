#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef void* queue_item_t;

typedef struct {
    queue_item_t *buffer;
    int head;
    int tail;
    int maxlen;
} queue_t;

void queue_init(queue_t *queue, void *storage, int size);
int queue_push(queue_t *queue, queue_item_t item);
int queue_pop(queue_t *queue, queue_item_t *item);

#endif