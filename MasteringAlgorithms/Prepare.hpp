//
//  Prepare.hpp
//  CrackingTheCodingInterview
//
//  Created by Moch Xiao on 11/29/15.
//  Copyright © 2015 Moch Xiao. All rights reserved.
//

#ifndef Prepare_hpp
#define Prepare_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n);
int facttail(int n, int a);
int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

#endif /* Prepare_hpp */
