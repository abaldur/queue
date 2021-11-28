#include "queue.h"

#include <stdio.h>
#include <assert.h>

// This simple type of queue only supports pushing and popping
// pointers to data.

int main()
{
    queue_t queue;
    int queue_storage[10];
    queue_init(&queue, queue_storage, 10);

    int data = 123;
    queue_push(&queue, (void*)&data);

    int *data_ptr;
    queue_pop(&queue, (void**)&data_ptr);

    assert(data == *data_ptr);

    return 0;
}