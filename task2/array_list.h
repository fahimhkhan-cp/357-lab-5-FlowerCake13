#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
    char **array;
    size_t capacity;
    size_t element_count;
} ArrayList;

ArrayList *array_list_new(void);
void array_list_add_to_end(ArrayList *arraylist, char* new_string);

#endif
