//
// Created by Moch Xiao on 12/7/15.
//

#include <stddef.h>
#include "queue.h"

int queue_enqueue(queue_type *queue, const void *data) {
    return linkedlist_insert_next(queue, linkedlist_tail(queue), data);
}

int queue_dequeue(queue_type *queue, void **data) {
    return linkedlist_remove_next(queue, NULL, data);
}