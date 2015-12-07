//
// Created by Moch Xiao on 12/7/15.
//

#ifndef MASTERINGALGORITHMS_SET_H
#define MASTERINGALGORITHMS_SET_H

#include "../linkedlist/linkedlist.h"

typedef linkedlist_type set_type;

void set_init(set_type *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
#define set_destroy linkedlist_destroy
int set_insert(set_type *set, const void *data);
int set_remove(set_type *set, void **data);
int set_union(set_type *result, const set_type *set1, const set_type *set2);
int set_intersection(set_type *result, const set_type *set1, const set_type *set2);
int set_difference(set_type *result, const set_type *set1, const set_type *set2);
int set_is_member(const set_type *set, const void *data);
int set_is_subset(const set_type *small_set, const set_type *big_set);
int set_is_equal(const set_type *set1, const set_type *set2);
#define set_size(set) ((set)->size)

#endif //MASTERINGALGORITHMS_SET_H
