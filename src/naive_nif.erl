-module(naive_nif).

-include("../include/constants.hrl").

-export([main/0]).

main() ->
	List = utils:parse(),

	Combination = naive_nif_interface:triple_sum(List, ?SUM),
	io:format("Naive nif combination: ~p", [Combination]).