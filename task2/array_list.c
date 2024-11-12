#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAP 4

ArrayList *array_list_new(void) {
    /* this function must dynamically allocate a new array list structure. This structure will need to track a resizeable array, its capacity, and the number of values currently within the array (its length?). The initial capacity of this resizeable array is up to you. */

    // malloc(<SIZE OF THING BEING ALLOCATED>)
    ArrayList *new_list = malloc(sizeof(ArrayList));

    // NULL CHECK NEW LIST
    if(new_list == NULL) {
        printf("ERROR: could not create new array list - malloc");
        exit(1);
    }

    // INIT ARRAY LIST INFO
        // char **array - size_t capacity - size_t element_count
    (*new_list).capacity = INIT_CAP;
    (*new_list).element_count = 0;

    (*new_list).array = malloc(INIT_CAP);
    if((*new_list).array == NULL) {
        printf("ERROR: could not create new array list - array malloc");
        exit(1);
    }

    return new_list;
}

void array_list_add_to_end(ArrayList *arraylist, char* new_string) {
    /* this function must take an array list and a string (char *) to add to the end of that list. If there is insufficient space to hold the string, the underlying array must be resized (you may use realloc); be sure to properly track the actual size of this array. The amount by which the underlying array is increased is up to you, but consider the cost of allocation vs. the cost of unused space. Note: each element within the array is a pointer to a string; this function is not concatenating all strings into one long string. */

    // CHECK IF ARRAY LIST IS AT CAPACITY
    if ((*arraylist).capacity <= (*arraylist).element_count) {
        // REALLOC - realloc(<current pointer>, <new size>)
        size_t new_capacity = (*arraylist).capacity * 2;
        char **new_array = realloc((*arraylist).array, new_capacity);

        // NULL CHECK NEW LIST
        if(new_array == NULL) {
            printf("ERROR: could not create new array list - array realloc");
            return;
        }

        (*arraylist).array = new_array;
        (*arraylist).capacity = new_capacity;
    }
    (*arraylist).array[(*arraylist).element_count] = new_string;  // add to the end of the array

    (*arraylist).element_count++;  // add to the number of elements
}
