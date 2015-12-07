//
// Created by Moch Xiao on 12/7/15.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_test.h"
#include "../stack/stack.h"

void stack_destroy_data(void *data) {
    // Do nothing...
}

void print_stack(stack_type *stack) {
    int stack_size = stack_size(stack);
    printf("stack_size: %i\n", stack_size);

    if (stack_size > 0) {
        const void *peek = stack_peek(stack);
        int peek_value = *((int *)peek);
        printf("peek_value: %i\n", peek_value);
    }

    linkedlist_node_type *node = linkedlist_head(stack);
    while (node) {
        const void *data = linkedlist_data(node);
        int data_value = *((int *)data);
        printf("%i\n", data_value);

        node = linkedlist_next(node);
    }
}

void test_stack() {
    printf("stack test start...\n");

    stack_type *stack = (stack_type *)malloc(sizeof(stack_type));
    stack_init(stack, stack_destroy_data);

    int firstItem = 2;
    stack_push(stack, (const void *)(&firstItem));

    int nextItem = 3;
    stack_push(stack, (const void *)(&nextItem));

    int endItem = 5;
    stack_push(stack, (const void *)(&endItem));

    print_stack(stack);

    printf("pop...\n");
    int *pop = (int *)malloc(sizeof(int));
    if (0 == stack_pop(stack, &pop)) {
        printf("poped value is: %i\n", *pop);
        print_stack(stack);
    }

    stack_destroy(stack);
    free(stack);
    stack = NULL;

    printf("stack test end.\n");
}