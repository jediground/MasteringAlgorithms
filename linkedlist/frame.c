//
//  frame.c
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#include "frame.h"
#include <stdlib.h>

int alloc_frame(linkedlist *frames) {
    int frame_number, *data;
    
    if (0 == linkedlist_size(frames)) {
        return -1;
    } else {
        if (0 != linkedlist_remove_next(frames, NULL, (void **)&data)) {
            // Return that a frame could not be retrieved
            return -1;
        } else {
            // Storage the number of the available frame
            frame_number = *data;
            free(data);
        }
    }
    
    return 0;
}

int free_frame(linkedlist *frames, int frame_number) {
    int *data;
    
    // Allocate storage for the frame number
    if (NULL == (data = (int *)malloc(sizeof(int)))) {
        return -1;
    }
    
    // Put the frame back in the list of available frames
    *data = frame_number;
    if (0 != linkedlist_insert_next(frames, NULL, data)) {
        return -1;
    }
    
    return 0;
}