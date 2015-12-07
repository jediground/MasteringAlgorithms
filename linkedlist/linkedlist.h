//
// Created by Moch Xiao on 12/2/15.
//

#ifndef MASTERINGALGORITHMS_LINKEDLIST_H
#define MASTERINGALGORITHMS_LINKEDLIST_H

/// Define a struct for linked list elements
typedef struct _linkedlist_node_type {
    void *data;
    struct _linkedlist_node_type *next;
} linkedlist_node_type;

/// Define a structure for linked lists
typedef struct _linkedlist_type {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    linkedlist_node_type *tail;
    linkedlist_node_type *head;
} linkedlist_type;

// Public interface
void linkedlist_init(linkedlist_type *list, void (*destroy)(void *data));
void linkedlist_destroy(linkedlist_type *list);
int linkedlist_insert_next(linkedlist_type *list, linkedlist_node_type *node, const void *data);
int linkedlist_remove_next(linkedlist_type *list, linkedlist_node_type *node, void **data);

#define linkedlist_size(list) ((list)->size)
#define linkedlist_head(list) ((list)->head)
#define linkedlist_tail(list) ((list)->tail)
#define linkedlist_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define linkedlist_is_tail(list, node) ((node)->next == NULL ? 1 : 0)
#define linkedlist_data(node) ((node)->data)
#define linkedlist_next(node) ((node)->next)

#endif //MASTERINGALGORITHMS_LINKEDLIST_H
