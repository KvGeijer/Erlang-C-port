#include <stdlib.h>
#include "array_list.h"

void array_list_init(array_list* list)
{
    list->alloced = STARTING_LENGTH;
    list->length = 0;
    list->array = malloc(STARTING_LENGTH * sizeof(*list->array));
}

void array_list_append(array_list* list, int elem)
{
    if (list->length == list->alloced) {
        list->alloced *= 2;
        list->array = realloc(list->array, list->alloced * sizeof(int));
    }
    list->array[list->length] = elem;
    list->length += 1;
}