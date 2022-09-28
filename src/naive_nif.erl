-module(naive_nif).

main() ->
	List = utils:parse(),

	Combination = naive_nif_interface:triple_sum(List, ?SUM),
	io:format("Naive nif combination: ~p", [Combination]).