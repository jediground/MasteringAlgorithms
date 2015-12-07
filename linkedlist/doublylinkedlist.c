//
// Created by Moch Xiao on 12/2/15.
//

#include "doublylinkedlist.h"
#include <string.h>
#include <stdlib.h>

void doublylinkedlist_init(doublylinkedlist_type *list, void(destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

void doublylinkedlist_destroy(doublylinkedlist_type *list) {
    void *data;

    // Remove each element
    for (; 0 == doublylinkedlist_remove(list, doublylinkedlist_tail(list), (void **)&data) &&
           NULL != list->destroy; ) {
        // Call a user-defined function to free dynamically allocated data
        list->destroy(data);
    }

    // No operations are allowed now, but clear the structure as a precaution
    memset(list, 0, sizeof(doublylinkedlist_type));

    return;
}

int doublylinkedlist_insert_next(doublylinkedlist_type *list, doublylinkedlist_node_type *node, const void *data) {
    doublylinkedlist_node_type *new_node;

    // Do not allow a NULL element unless th list is empty
    if (NULL == node && 0 != doublylinkedlist_size(list)) {
        return -1;
    }

    // Allocated storage for the element
    if (NULL == (new_node = (doublylinkedlist_node_type *)malloc(sizeof(doublylinkedlist_node_type)))) {
        return -1;
    }

    // Insert tht new element into the list
    new_node->data = (void *)data;
    if (0 == doublylinkedlist_size(list)) {
        // Handle insertion when the list is empty
        list->head = new_node;
        list->head->previous = NULL;
        list->head->next = NULL;
        list->tail = new_node;
    } else {
        // Handle insertion when the list is empty
        new_node->next = node->next;
        new_node->previous = node;

        if (NULL == node->next) {
            list->tail = new_node;
        } else {
            node->next = new_node;
        }

        node->next = new_node;
    }

    // Adjust the size of the list to account for the inserted element
    list->size++;

    return 0;
}

int doublylinkedlist_insert_previous(doublylinkedlist_type *list, doublylinkedlist_node_type *node, const void *data) {
    doublylinkedlist_node_type *new_node;

    // Do not allow a NULL element unless th list is empty
    if (NULL == node && 0 != doublylinkedlist_size(list)) {
        return -1;
    }

    // Allocated storage for the element
    if (NULL == (new_node = (doublylinkedlist_node_type *)malloc(sizeof(doublylinkedlist_node_type)))) {
        return -1;
    }

    // Insert tht new element into the list
    new_node->data = (void *)data;
    if (0 == doublylinkedlist_size(list)) {
        // Handle insertion when the list is empty
        list->head = new_node;
        list->head->previous = NULL;
        list->head->next = NULL;
        list->tail = new_node;
    } else {
        // Handle insertion when the list is not empty
        new_node->next = node;
        new_node->previous = node->previous;

        if (NULL == node->previous) {
            list->head = new_node;
        } else {
            node->previous->next = new_node;
        }

        node->previous = new_node;
    }

    // Adjust the size of the list to account for the inserted element
    list->size++;

    return 0;
}

int doublylinkedlist_remove(doublylinkedlist_type *list, doublylinkedlist_node_type *node, void **data) {
    // Do not allow a NULL element or removal form an empty list
    if (NULL == node || 0 == doublylinkedlist_size(list)) {
        return -1;
    }

    // Remove the element from the list
    *data = node->data;
    if (node == list->head) {
        // Handle removal from the head of the list
        if (NULL == list->head) {
            list->tail = NULL;
        } else {
            node->next->previous = NULL;
        }
    } else {
        // Handle removal from other than the head of the list
        node->previous->next = node->next;
        if (NULL == node->next) {
            list->tail = node->previous;
        } else {
            node->next->previous = node->previous;
        }
    }

    // Free the storage allocated by the abstract datatype
    free(node);

    // Adjust the size of the list to account for the remoed element
    list->size--;

    return 0;
}
