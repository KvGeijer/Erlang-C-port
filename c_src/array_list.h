#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define STARTING_LENGTH 64

typedef struct array_list {
    unsigned int length;
    unsigned int alloced;
    unsigned int* array;
} array_list;

void array_list_init(array_list* arr);
void array_list_append(array_list* list, int elem);

#endif
