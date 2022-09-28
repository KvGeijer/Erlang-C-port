#include <stdlib.h>
#include "array_list.h"

void array_list_init(array_list* list)
{
    list->alloced = STARTING_LENGTH;
    list->length = 0;
    list->array = malloc(STARTING_LENGTH * sizeof(*list->array));
}