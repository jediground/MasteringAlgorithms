//
//  linkedlist.c
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#include "linkedlist.h"

void linkedlist_init(linkedlist *list, void (*destory)(void *data)) {
    list->size = 0;
    list->destroy = destory;
    list->head = NULL;
    list->tail = NULL;
    
    return;
}

void linkedlist_destroy(linkedlist *list) {
    void *data;
    
    // Remove each element
    for (; linkedlist_size(list) > 0; ) {
        if (0 == linkedlist_remove_next(list, NULL, (void **)&data) &&
            NULL != list->destroy) {
            list->destroy(data);
        }
    }
    
    // No operations are allowed now, but clear the structure as a precaution
    memset(list, 0, sizeof(list));
    
    return;
}

int linkedlist_insert_next(linkedlist *list, linkedlist_node *node, const void *data) {
    return 0;
}

int linkedlist_remove_next(linkedlist *list, linkedlist_node *node, void **data) {
    return 0;
}