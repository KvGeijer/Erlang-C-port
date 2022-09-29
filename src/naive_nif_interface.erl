-module(naive_nif_interface).

-export([triple_sum/2]).
-nifs([triple_sum/2]).
-on_load(init/0).

init() ->
    ok = erlang:load_nif("./naive_c_nif", 0).

triple_sum(_List, _Sum) ->
    io:format("asfhakbfhaefbnöksbg~n"),
    erlang:nif_error("Could not load the naive C nif").

