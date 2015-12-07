//
// Created by Moch Xiao on 12/2/15.
//

#ifndef MASTERINGALGORITHMS_DOUBLYLINKEDLIST_H
#define MASTERINGALGORITHMS_DOUBLYLINKEDLIST_H

/// Define a structure for doubly-linked list elements
typedef struct _doublylinkedlist_node_type {
    void *data;
    struct _doublylinkedlist_node_type *previous;
    struct _doublylinkedlist_node_type *next;
} doublylinkedlist_node_type;

/// Define a structure for doubly-linked lists
typedef struct _doublylinkedlist_type {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    doublylinkedlist_node_type *head;
    doublylinkedlist_node_type *tail;
} doublylinkedlist_type;

// Public interface
void doublylinkedlist_init(doublylinkedlist_type *list, void(destroy)(void *data));
void doublylinkedlist_destroy(doublylinkedlist_type *list);
int doublylinkedlist_insert_next(doublylinkedlist_type *list, doublylinkedlist_node_type *node, const void *data);
int doublylinkedlist_insert_previous(doublylinkedlist_type *list, doublylinkedlist_node_type *node, const void *data);
int doublylinkedlist_remove(doublylinkedlist_type *list, doublylinkedlist_node_type *node, void **data);

#define doublylinkedlist_size(list) ((list)->size)
#define doublylinkedlist_head(list) ((list)->head)
#define doublylinkedlist_tail(list) ((list)->tail)
#define doublylinkedlist_is_head(node) ((NULL == (node)->previous) ? 1 : 0)
#define doublylinkedlist_is_tail(node) ((NULL == (node)->next) ? 1 : 0)
#define doublylinkedlist_data(node) ((node)->data)
#define doublylinkedlist_next(node) ((ndoe)->next)
#define doublylinkedlist_previous(node) ((node)->previous)

#endif //MASTERINGALGORITHMS_DOUBLYLINKEDLIST_H
