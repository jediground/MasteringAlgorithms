//
//  circularlinkedlist_type.c
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#include "circularlinkedlist.h"
#include <string.h>
#include <stdlib.h>

void circularlinkedlist_init(circularlinkedlist_type *list, void(*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;
}

void circularlinkedlist_destroy(circularlinkedlist_type *list) {
    void *data;

    // Remove each elements
    for (; 0 < circularlinkedlist_size(list); ) {
        if (0 == circularlinkedlist_remove_next(list, list->head, (void **)&data) &&
            NULL != list->destroy) {
            // Call a user-defined function to free dynamically allocated data
            list->destroy(data);
        }
    }

    // No operations are allowed now, but clear the structure as a precaution
    memset(list, 0, sizeof(circularlinkedlist_type));

    return;
}

int circularlinkedlist_insert_next(circularlinkedlist_type *list, circularlinkedlist_node_type *node, const void *data) {
    circularlinkedlist_node_type *new_node;

    // Allocate storage for the element
    if (NULL == (new_node = (circularlinkedlist_node_type *)malloc(sizeof(circularlinkedlist_node_type)))) {
        return -1;
    }

    // Insert the element into the list
    new_node->data = (void *)data;
    if (0 == circularlinkedlist_size(list)) {
        // Handle insertion when the list is empty
        new_node->next = new_node;
        list->head = new_node;
    } else {
        // Handle insertion when the list is not empty
        new_node->next = node;
        node->next = new_node;
    }

    // Adjust the size of the list to account for the inserted element
    list->size++;

    return 0;
}

int circularlinkedlist_remove_next(circularlinkedlist_type *list, circularlinkedlist_node_type *node, void **data) {
    circularlinkedlist_node_type *old_node;

    // Do not allow removal from an empty list
    if (0 == circularlinkedlist_size(list)) {
        return -1;
    }

    // Remove the element from the list
    *data = node->next->data;
    if (node == node->next) {
        // Handle removing the last element
        old_node = node->next;
        list->head = NULL;
    } else {
        // Handle removing other than the last element
        old_node = node->next;
        node->next = node->next->next;
        if (old_node == circularlinkedlist_head(list)) {
            list->head = old_node->next;
        }
    }

    // Free the storage allocated by the abstract datatype
    free(old_node);

    // Adjust the size of the list to account for the remoed element
    list->size--;

    return 0;
}
