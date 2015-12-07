//
//  frame.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef frame_h
#define frame_h

#include <stdio.h>

#include "../linkedlist/linkedlist.h"

int alloc_frame(linkedlist_type *frames);
int free_frame(linkedlist_type *frames, int frame_number);

#endif /* frame_h */
