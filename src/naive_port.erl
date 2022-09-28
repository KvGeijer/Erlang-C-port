-module(naive_port).
-export([main/0]).

-include("../include/constants.hrl").

-define(BYTE, 8).

main() ->
	%% Use packet 2 as we mostly want to send integers with 16 bits
    Port = open_port({spawn, "./naive_c_port"}, [{packet, 2}]),
	List = utils:parse(),

	send_int(Port, ?SUM),
	send_list(Port, List),
	receive_solution(Port).

send_int(Port, Int) ->
	Port ! {self(), {command, encode(Int)}}.

send_list(Port, [Head|Rest]) ->
	send_int(Port, Head),
	send_list(Port, Rest);
send_list(Port, []) ->
	send_int(Port, 0).

receive_solution(Port) ->
	%% This actually works, it receives three messages
	Combination = [receive_int(Port) || _ <- [1, 2, 3]],
	io:format("Naive port combination: ~p", [Combination]).

receive_int(Port) ->
	receive
		{Port, {data, Data}} ->
			decode(Data)
	end.

encode(Nbr) ->
	First8 = Nbr bsr ?BYTE,
	Last8 = Nbr band ((1 bsl ?BYTE) - 1),
	[First8, Last8].

decode([X1, X2]) ->
	(X2 bsl ?BYTE) + X1;
decode(_) ->
	error("Incorrect message size~n").