#include <stdio.h>

#include "naive_solution.h"


void naive_find_result(array_list* list, int sum, int* result)
{
    for (int i = 0; i < list->length; i++)
    {
        for (int j = i; j < list->length; j++)
        {
            for (int k = j; k < list->length; k++)
            {
                if (list->array[i] + list->array[j] + list->array[k] == sum)
                {
                    result[0] = list->array[i];
                    result[1] = list->array[j];
                    result[2] = list->array[k];
                    return ;
                }
            }
        }
    }
}