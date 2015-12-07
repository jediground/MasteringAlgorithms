//
// Created by Moch Xiao on 12/7/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "queue_test.h"
#include "../queue/queue.h"

void queue_destroy_data(void *data) {
    // Do nothing...
}

void queue_print(queue_type *queue) {
    int queue_size = queue_size(queue);
    printf("queue_size: %i\n", queue_size);

    if (queue_size > 0) {
        const void *peek = queue_peek(queue);
        int peek_value = *((int *)peek);
        printf("peek_value: %i\n", peek_value);
    }

    linkedlist_node_type *node = linkedlist_head(queue);
    while (node) {
        const void *data = linkedlist_data(node);
        int data_value = *((int *)data);
        printf("%i\n", data_value);

        node = linkedlist_next(node);
    }
}

void test_queue() {
    queue_type *queue = (queue_type *)malloc(sizeof(queue_type));
    queue_init(queue, queue_destroy_data);

    int firstItem = 2;
    queue_enqueue(queue, (const void *)(&firstItem));

    int nextItem = 3;
    queue_enqueue(queue, (const void *)(&nextItem));

    int endItem = 5;
    queue_enqueue(queue, (const void *)(&endItem));

    queue_print(queue);

    printf("dequeue...\n");
    int *dequeue = (int *)malloc(sizeof(int));
    if (0 == queue_dequeue(queue, &dequeue)) {
        printf("dequeued value is: %i\n", *dequeue);
        queue_print(queue);
    }

    queue_destroy(queue);
    free(queue);
    queue = NULL;
}