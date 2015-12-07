//
// Created by Moch Xiao on 12/7/15.
//

#ifndef MASTERINGALGORITHMS_STACK_H
#define MASTERINGALGORITHMS_STACK_H

#include "../linkedlist/linkedlist.h"

typedef linkedlist_type stack_type;

#define stack_init linkedlist_init
#define stack_destroy linkedlist_destroy

int stack_push(stack_type *stack, const void *data);
int stack_pop(stack_type *stack, void **data);

#define stack_peek(stack) (NULL == (stack)->head ? NULL : (stack)->head->data)
#define stack_size linkedlist_size

#endif //MASTERINGALGORITHMS_STACK_H
