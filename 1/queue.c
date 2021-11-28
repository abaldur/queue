#include "queue.h"

void queue_init(queue_t *queue, void *storage, int size)
{
    *queue = (queue_t){
        .buffer = storage,
        .head = 0,
        .tail = 0,
        .maxlen = size
    };
}

int queue_push(queue_t *queue, queue_item_t item)
{
    int next;

    next = queue->head + 1;  // next is where head will point to after this write.
    if (next >= queue->maxlen)
        next = 0;

    if (next == queue->tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    queue->buffer[queue->head] = item;  // Load data and then move
    queue->head = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}

int queue_pop(queue_t *queue, queue_item_t* item)
{
    int next;

    if (queue->head == queue->tail)  // if the head == tail, we don't have any data
        return -1;

    next = queue->tail + 1;  // next is where tail will point to after this read.
    if(next >= queue->maxlen)
        next = 0;

    *item = queue->buffer[queue->tail];  // Read data and then move
    queue->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}