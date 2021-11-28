#include "queue.h"
#include <string.h>

static size_t _size_available(queue_t *queue)
{
    if (queue->tail > queue->head)
    {
        return queue->tail - queue->head;
    }
    else if (queue->head > queue->tail)
    {
        return queue->total_space - queue->head + queue->tail;
    }
    else
    {
        
    }
    return 0;
}

void queue_init(queue_t *queue, void *storage_buf, size_t storage_len)
{
    // to make debugging easier
    memset(storage_buf, 0x0, storage_len);

    *queue = (queue_t){
        .storage = storage_buf,
        .total_space = storage_len,
        .head = 0,
        .tail = 0,
        .maxlen = 0
    };
}

// int circ_bbuf_push(circ_bbuf_t *c, void *data)
// {
//     int next;

//     next = c->head + 1;  // next is where head will point to after this write.
//     if (next >= c->maxlen)
//         next = 0;

//     if (next == c->tail)  // if the head + 1 == tail, circular buffer is full
//         return -1;

//     c->buffer[c->head] = data;  // Load data and then move
//     c->head = next;             // head to next data offset.
//     return 0;  // return success to indicate successful push.
// }

// int circ_bbuf_pop(circ_bbuf_t *c, void **data)
// {
//     int next;

//     if (c->head == c->tail)  // if the head == tail, we don't have any data
//         return -1;

//     next = c->tail + 1;  // next is where tail will point to after this read.
//     if(next >= c->maxlen)
//         next = 0;

//     *data = c->buffer[c->tail];  // Read data and then move
//     c->tail = next;              // tail to next offset.
//     return 0;  // return success to indicate successful push.
// }