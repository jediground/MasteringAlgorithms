//
//  replacepage.c
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#include "replacepage.h"

int replace_page(circularlinkedlist_node **current) {
    // Circle through the list of pages untill one is found to replace
    
    for (; 0 != ((page *)(*current)->data)->reference; ) {
        ((page *)(*current)->data)->reference = 0;
        *current = circularlinkedlist_next(*current);
    }
    
    return ((page *)(*current)->data)->number;
}