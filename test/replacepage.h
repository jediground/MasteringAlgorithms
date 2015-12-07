//
// Created by Moch Xiao on 12/2/15.
//

#ifndef MASTERINGALGORITHMS_REPLACEPAGE_H
#define MASTERINGALGORITHMS_REPLACEPAGE_H

#include "../linkedlist/circularlinkedlist.h"

// Define a structure for information about pages
typedef struct _page {
    int number;
    int reference;
} page;

// Public interface
int replace_page(circularlinkedlist_node_type **current);

#endif //MASTERINGALGORITHMS_REPLACEPAGE_H
