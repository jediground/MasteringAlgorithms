//
//  prepare.h
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#ifndef prepare_h
#define prepare_h

#include <stdio.h>
#include <stdlib.h>

int fact(int n);
int facttail(int n, int a);
int issort(void *data, int size, size_t esize, int (*compare)(const void *key1, const void *key2));

#endif /* prepare_h */
