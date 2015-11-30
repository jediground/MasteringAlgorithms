//
//  linkedlist.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <stdlib.h>

/// Define a struct for linked list elements
typedef struct _linkedlist_node {
    void *data;
    struct _linkedlist_node *next;
} linkedlist_node;

/// Define a structure for linked lists
typedef struct _linkedlist {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    struct _linkedlist_node *head;
    struct _linkedlist_node *tail;
} linkedlist;

// Public interface
void linkedlist_init(linkedlist *list, void (*destory)(void *data));
void linkedlist_destroy(linkedlist *list);
int linkedlist_insert_next(linkedlist *list, linkedlist_node *node, const void *data);
int linkedlist_remove_next(linkedlist *list, linkedlist_node *node, void **data);

#define linkedlist_size(list) ((list)->size)
#define linkedlist_head(list) ((list)->head)
#define linkedlist_tail(list) ((list)->tail)
#define linkedlist_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define linkedlist_is_tail(list, node) ((node)->next == NULL ? 1 : 0)
#define linkedlist_data(node) ((node)->data)
#define linkedlist_next(node) ((node)->next)


#endif /* linkedlist_h */
