//
//  circularlinkedlist.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef MASTERINGALGORITHMS_CIRCULARLINKEDLIST_H
#define MASTERINGALGORITHMS_CIRCULARLINKEDLIST_H

#include <stdio.h>

/// Define a structure for circular list elements
typedef struct _circularlinkedlist_node {
    void *data;
    struct _circularlinkedlist_node *next;
} circularlinkedlist_node;

/// Define a structure for circular lists
typedef struct _circularlinkedlist {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    circularlinkedlist_node *head;
} circularlinkedlist;

// Public interface
void circularlinkedlist_init(circularlinkedlist *list, void(*destroy)(void *data));
void circularlinkedlist_destroy(circularlinkedlist *list);
int circularlinkedlist_insert_next(circularlinkedlist *list, circularlinkedlist_node *node, const void *data);
int circularlinkedlist_remove_next(circularlinkedlist *list, circularlinkedlist_node *node, void **data);

#define circularlinkedlist_size(list) ((list)->size)
#define circularlinkedlist_head(list) ((list)->head)
#define circularlinkedlist_tail(list) ((list)->tail)
#define circularlinkedlist_data(node) ((node)->data)
#define circularlinkedlist_next(node) ((node)->next)

#endif // MASTERINGALGORITHMS_CIRCULARLINKEDLIST_H
