//
//  prepare.c
//  MasteringAlgorithms
//
//  Created by Moch Xiao on 11/30/15.
//  Copyright © 2015 Moch. All rights reserved.
//

#include "prepare.h"

int fact(int n) {
    if (0 > n) {
        return 0;
    } else if (0 == n) {
        return 1;
    } else if (1 == n) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int facttail(int n, int a) {
    if (0 > n) {
        return 0;
    } else if (0 == n) {
        return 1;
    } else if (1 == n) {
        return a;
    } else {
        return facttail(n - 1, n * a);
    }
}

int issort(void *data, int size, size_t esize, int (*compare)(const void *key1, const void *key2)) {
    char *a = (char*)data;
    void *key;
    int i, j;
    
    // Allocate storage for the key element
    if (NULL == (key = (char *)malloc(esize))) {
        return -1;
    }
    
    // Reoeatedkt insert a key element among the sorted elements
    for (j = 1; j < size; j++) {
        memcpy(key, &a[j * esize], esize);
        i = j - 1;
        
        // Determine the postion at which to insert the key elements
        for (; i >= 0 && compare(&a[i * esize], key) > 0;) {
            memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
            i--;
        }
        memcpy(&a[(i + 1) * esize], key, esize);
    }
    
    // Free the stroage allocated for sorting
    free(key);
    
    return 0;
}