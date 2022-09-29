#include <erl_nif.h>
#include <stdio.h>
#include <stdlib.h>

#include "naive_solution.h"
#include "array_list.h"

static int parse_list(ErlNifEnv* env, ERL_NIF_TERM erl_list, array_list* list)
{
    ERL_NIF_TERM *head, *tail;
    int list_elem;

    *tail = erl_list;

    while(enif_get_list_cell(env, *tail, head, tail))
    {
        if (!enif_get_int(env, *head, &list_elem)) {
            return 0;
        }
        array_list_append(list, list_elem);
    }

    return 1;
}

static ERL_NIF_TERM triple_sum_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int sum;
    int* result = calloc(3, sizeof(int));
    array_list list;

    if (!enif_get_int(env, argv[1], &sum)) {
	    return enif_make_badarg(env);
    }

    array_list_init(&list);

    // This destroys the stack in some way?
    if (!(parse_list(env, argv[0], &list))) {
        return enif_make_badarg(env);
    }

    naive_find_result(list, sum, &(extra_result[0]));

    return enif_make_tuple3(env, result[0], result[1], result[2]);
}

static ErlNifFunc nif_funcs[] = {
    {"triple_sum", 2, triple_sum_nif}
};

ERL_NIF_INIT(naive_nif_interface, nif_funcs, NULL, NULL, NULL, NULL)