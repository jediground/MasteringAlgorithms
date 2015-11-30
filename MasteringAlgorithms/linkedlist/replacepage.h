//
//  replacepage.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef replacepage_h
#define replacepage_h

#include <stdio.h>
#include "circularlinkedlist.h"

// Define a structure for information about pages
typedef struct _page {
    int number;
    int reference;
} page;

// Public interface
int replace_page(circularlinkedlist_node **current);

#endif /* replacepage_h */
