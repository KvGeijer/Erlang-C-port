#include <erl_nif.h>

#include "naive_solution.h"
#include "array_list.h"

static array_list* parse_list(ErlNifEnv* env, ERL_NIF_TERM erl_list)
{
    ERL_NIF_TERM *head, *tail;
    int list_elem;
    array_list* list;

    array_list_init(list);

    *tail = erl_list;

    while(enif_get_list_cell(env, *tail, head, tail))
    {
        if (!enif_get_int(env, *head, &list_elem)) {
            return NULL;
        }
        array_list_append(list, list_elem);
    }

    return list;
}

static ERL_NIF_TERM triple_sum_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int sum, result[3];
    array_list* list;

    if (!enif_get_int(env, argv[1], &sum)) {
	    return enif_make_badarg(env);
    }
    if (!(list = parse_list(env, argv[0]))) {
        return enif_make_badarg(env);
    }

    naive_find_result(list, sum, result);
    free(list);

    return enif_make_tuple3(env, result[0], result[1], result[2]);
}

static ErlNifFunc nif_funcs[] = {
    {"triple_sum", 1, triple_sum_nif}
};

ERL_NIF_INIT(naive_nif_interface, nif_funcs, NULL, NULL, NULL, NULL)