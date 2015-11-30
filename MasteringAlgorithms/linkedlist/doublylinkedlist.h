//
//  doublylinkedlist.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef doublylinkedlist_h
#define doublylinkedlist_h

#include <stdio.h>

/// Define a structure for doubly-linked list elements
typedef struct _doublylinkedlist_node {
    void *data;
    struct _doublylinkedlist_node *previous;
    struct _doublylinkedlist_node *next;
} doublylinkedlist_node;

/// Define a structure for doubly-linked lists
typedef struct _doublylinkedlist {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    doublylinkedlist_node *head;
    doublylinkedlist_node *tail;
} doublylinkedlist;

// Public interface
void doublylinkedlist_init(doublylinkedlist *list, void(destroy)(void *data));
void doublylinkedlist_destroy(doublylinkedlist *list);
int doublylinkedlist_insert_next(doublylinkedlist *list, doublylinkedlist_node *node, const void *data);
int doublylinkedlist_insert_previous(doublylinkedlist *list, doublylinkedlist_node *node, const void *data);
int doublylinkedlist_remove(doublylinkedlist *list, doublylinkedlist_node *node, void **data);

#define doublylinkedlist_size(list) ((list)->size)
#define doublylinkedlist_head(list) ((list)->head)
#define doublylinkedlist_tail(list) ((list)->tail)
#define doublylinkedlist_is_head(node) ((NULL == (node)->previous) ? 1 : 0)
#define doublylinkedlist_is_tail(node) ((NULL == (node)->next) ? 1 : 0)
#define doublylinkedlist_data(node) ((node)->data)
#define doublylinkedlist_next(node) ((ndoe)->next)
#define doublylinkedlist_previous(node) ((node)->previous)

#endif /* doublylinkedlist_h */
