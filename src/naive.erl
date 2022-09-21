-module(naive).

-export([main/0]).

-include("../include/constants.hrl").

main() ->
    List = utils:parse(),
    Combinations = [{A, B, C} || A <- List
                               , B <- List
                               , C <- List
                                    , A + B + C == ?SUM],

    Combination = lists:nth(1, Combinations),
    io:format("Naive combination: ~p", [Combination]).