//
// Created by Moch Xiao on 12/7/15.
//

#include <stddef.h>
#include "set.h"

void set_init(set_type *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)) {
    linkedlist_init(set, destroy);
    set->match = match;

    return;
}

int set_insert(set_type *set, const void *data) {
    if (set_is_member(set, data)) {
        return 1;
    }

    return linkedlist_insert_next(set, linkedlist_tail(set), data);
}

int set_remove(set_type *set, void **data) {
    linkedlist_node_type *member, *previous;
    previous = NULL;

    // Find the member to remove
    for (member = linkedlist_head(set); NULL != member ; member = linkedlist_next(member)) {
        if (set->match(*data, linkedlist_data(member))) {
            break;
        }

        previous = member;
    }

    // Return if the member was not found
    if (NULL == member) {
        return -1;
    }

    // Remove the member
    return linkedlist_remove_next(set, previous, data);
}

int set_union(set_type *result, const set_type *set1, const set_type *set2) {
    linkedlist_node_type *member;
    void *data;

    set_init(result, set1->match, NULL);

    // Insert the member of the first set
    for (member = linkedlist_head(set1); NULL != member; member = linkedlist_next(member)) {
        data = linkedlist_data(member);
        if (0 != linkedlist_insert_next(result, linkedlist_tail(result), data)) {
            set_destroy(result);
            return -1;
        }
    }

    // Insert the member of the second set
    for (member = linkedlist_head(set2); NULL != member ; member = linkedlist_next(member)) {
        if (set_is_member(set1, linkedlist_data(member))) {
            continue;
        } else {
            data = linkedlist_data(member);
            if (0 != linkedlist_insert_next(result, linkedlist_tail(result), data)) {
                set_destroy(result);
                return -1;
            }
        }
    }

    return 0;
}

int set_intersection(set_type *result, const set_type *set1, const set_type *set2) {
    linkedlist_node_type *member;
    void *data;

    set_init(result, set1->match, NULL);

    // Insert the member present in both sets
    for (member = linkedlist_head(set1); NULL != member; member = linkedlist_next(member)) {
        if (set_is_member(set2, linkedlist_data(member))) {
            data = linkedlist_data(member);
            if (0 != linkedlist_insert_next(set1, linkedlist_tail(set1), data)) {
                set_destroy(set1);
                return -1;
            }
        }
    }

    return 0;
}

int set_difference(set_type *result, const set_type *set1, const set_type *set2) {
    linkedlist_node_type *member;
    void *data;

    set_init(result, set1->match, NULL);

    // Insert the member from set1 not in set2
    for (member = linkedlist_head(set1); NULL != member; member = linkedlist_next(member)) {
        if (!set_is_member(set2, linkedlist_data(member))) {
            data = linkedlist_data(member);

            if (0 != linkedlist_insert_next(result, linkedlist_tail(result), data)) {
                return -1;
            }
        }
    }

    return 0;
}

int set_is_member(const set_type *set, const void *data) {
    linkedlist_node_type *member;

    // Determine if the data is a member of the set
    for (member = linkedlist_head(set), NULL != member; member = linkedlist_next(member)) {
        if (set->match(data, linkedlist_data(member))) {
            return 1;
        }
    }

    return 0;
}

int set_is_subset(const set_type *small_set, const set_type *big_set) {
    linkedlist_node_type *member;

    // Do a quick test to rule some cases
    if (set_size(small_set) > set_size(big_set)) {
        return 0;
    }

    // Determine if small_set is a subset of big_set
    for (member = linkedlist_head(small_set); NULL != member; member = linkedlist_next(member)) {
        if (!set_is_member(big_setm, linkedlist_data(member))) {
            return 0;
        }
    }

    return 1;
}

int set_is_equal(const set_type *set1, const set_type *set2) {
    if (set_size(set1) != set_size(set2)) {
        return 0;
    }

    return set_is_subset(set1, set2);
}
