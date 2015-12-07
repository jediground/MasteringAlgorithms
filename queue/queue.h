//
// Created by Moch Xiao on 12/7/15.
//

#ifndef MASTERINGALGORITHMS_QUEUE_H
#define MASTERINGALGORITHMS_QUEUE_H

#include "../linkedlist/linkedlist.h"

typedef linkedlist_type queue_type;

#define queue_init linkedlist_init
#define queue_destroy linkedlist_destroy

int queue_enqueue(queue_type *queue, const void *data);
int queue_dequeue(queue_type *queue, void **data);

#define queue_peek(queue) (NULL ==  (queue)->head ? NULL : (queue)->head->data)
#define queue_size linkedlist_size

#endif //MASTERINGALGORITHMS_QUEUE_H
