//
// Created by Moch Xiao on 12/7/15.
//

#include <stddef.h>
#include "stack.h"

int stack_push(stack_type *stack, const void *data) {
    return linkedlist_insert_next(stack, NULL, data);
}

int stack_pop(stack_type *stack, void **data) {
    return linkedlist_remove_next(stack, NULL, data);
}