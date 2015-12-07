//
// Created by Moch Xiao on 12/7/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist_test.h"
#include "../linkedlist/linkedlist.h"

void linkedlist_destroy_data(void *data) {
    // Do nothing...
}

void print_linkedlist(linkedlist_type *list) {
    linkedlist_node_type *node = linkedlist_head(list);
    if (node) {
        printf("`head_node` is head: %i\n", linkedlist_is_head(list, node));
        printf("head: %i\n", *((int *)linkedlist_data(node)));
    }

    while (node) {
        const void *data = linkedlist_data(node);
        int data_value = *((int *)data);
        printf("%i\n", data_value);

        node = linkedlist_next(node);
    }

    int size = linkedlist_size(list);
    printf("size: %i\n", size);

    if (size > 0) {
        linkedlist_node_type *tail_node = linkedlist_tail(list);

        printf("`tail_node` is tail: %i\n", linkedlist_is_tail(list, tail_node));

        int tail = *((int *)linkedlist_data(tail_node));
        printf("tail: %i\n", tail);
    }
}

void test_linkedlist() {
    printf("linkedlist test start...\n");

    linkedlist_type *list = (linkedlist_type *)malloc(sizeof(linkedlist_type));
    linkedlist_init(list, linkedlist_destroy_data);

    int firstItem = 2;
    linkedlist_insert_next(list , NULL, (const void *)(&firstItem));

    int nextItem = 3;
    linkedlist_insert_next(list , NULL, (const void *)(&nextItem));

    int endItem = 5;
    linkedlist_insert_next(list , NULL, (const void *)(&endItem));

    print_linkedlist(list);

    printf("remove...\n");
    int *remove = (int *)malloc(sizeof(int));
    linkedlist_remove_next(list, NULL, (void **)&remove);
    printf("removed item is: %i\n", *remove);

    print_linkedlist(list);

    linkedlist_destroy(list);
    free(list);
    list = NULL;

    printf("linkedlist test end.\n");
}
