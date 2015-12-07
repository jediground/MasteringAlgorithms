//
//  circularlinkedlist_type.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef MASTERINGALGORITHMS_CIRCULARLINKEDLIST_H
#define MASTERINGALGORITHMS_CIRCULARLINKEDLIST_H

#include <stdio.h>

/// Define a structure for circular list elements
typedef struct _circularlinkedlist_node_type {
    void *data;
    struct _circularlinkedlist_node_type *next;
} circularlinkedlist_node_type;

/// Define a structure for circular lists
typedef struct _circularlinkedlist_type {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    circularlinkedlist_node_type *head;
} circularlinkedlist_type;

// Public interface
void circularlinkedlist_init(circularlinkedlist_type *list, void(*destroy)(void *data));
void circularlinkedlist_destroy(circularlinkedlist_type *list);
int circularlinkedlist_insert_next(circularlinkedlist_type *list, circularlinkedlist_node_type *node, const void *data);
int circularlinkedlist_remove_next(circularlinkedlist_type *list, circularlinkedlist_node_type *node, void **data);

#define circularlinkedlist_size(list) ((list)->size)
#define circularlinkedlist_head(list) ((list)->head)
#define circularlinkedlist_tail(list) ((list)->tail)
#define circularlinkedlist_data(node) ((node)->data)
#define circularlinkedlist_next(node) ((node)->next)

#endif // MASTERINGALGORITHMS_CIRCULARLINKEDLIST_H
