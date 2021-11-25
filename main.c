#include "queue.h"

#include <stdio.h>

int main()
{
    CIRC_BBUF_DEF(my_circ_buf, 32);

    uint8_t in_data = 0x55;
    uint8_t *out_data = NULL;

    // Push pointer to object
    if (circ_bbuf_push(&my_circ_buf, (void*)&in_data)) {
        printf("Out of space in CB\n");
        return -1;
    }

    // Retrieve pointer to object
    if (circ_bbuf_pop(&my_circ_buf, (void**)&out_data)) {
        printf("CB is empty\n");
        return -1;
    }

    // here in_data = in_data = 0x55;
    printf("Push: 0x%x\n", in_data);
    printf("Pop:  0x%x\n", *out_data);

    return 0;
}