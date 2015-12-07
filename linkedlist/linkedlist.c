//
// Created by Moch Xiao on 12/2/15.
//

#include "linkedlist.h"
#include <string.h>
#include <stdlib.h>

void linkedlist_init(linkedlist_type *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

void linkedlist_destroy(linkedlist_type *list) {
    void *data;

    // Remove each element
    for (; linkedlist_size(list) > 0; ) {
        if (0 == linkedlist_remove_next(list, NULL, &data) &&
            NULL != list->destroy) {
            list->destroy(data);
        }
    }

    // No operations are allowed now, but clear the structure as a precaution
    memset(list, 0, sizeof(linkedlist_type));

    return;
}

int linkedlist_insert_next(linkedlist_type *list, linkedlist_node_type *node, const void *data) {
    linkedlist_node_type *new_node;

    // Allocate storage for the element
    if (NULL == (new_node = (linkedlist_node_type *)malloc(sizeof(linkedlist_node_type)))) {
        return -1;
    }

    // Insert the element into the list
    new_node->data = (void *)data;
    if (NULL == node) {
        // Handle insertion at the head of the list
        if (linkedlist_size(list) == 0) {
            list->tail = new_node;
        }

        new_node->next = list->head;
        list->head = new_node;
    } else {
        // Handle insertion somewhere other than at the head
        if (NULL == node->next) {
            list->tail = new_node;
        }

        new_node->next = node->next;
        node->next = new_node;
    }

    // Adjust the size of the list to account for the inserted element
    list->size++;

    return 0;
}

int linkedlist_remove_next(linkedlist_type *list, linkedlist_node_type *node, void **data) {
    linkedlist_node_type *old_node;

    // Do not allow removeal from empty lsit
    if (0 == linkedlist_size(list)) {
        return -1;
    }

    // Remove the element from the list
    if (NULL == node) {
        // Handle removal from the head of the list
        *data = list->head->data;
        old_node = list->head;
        list->head = list->head->next;

        if (1 == linkedlist_size(list)) {
            list->tail = NULL;
        }
    } else {
        // Handle removal from somewhere other than the head
        if (NULL == node->next) {
            return -1;
        }

        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;

        if (NULL == node->next) {
            list->tail = node;
        }
    }

    // Free the storage allocated by the abstract datatype
    free(old_node);

    // Adjust the size of the list to account for the remoed element
    list->size--;

    return 0;
}
