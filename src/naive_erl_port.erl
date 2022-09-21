-module(naive_erl_port).
-export([main/0]).

-define(BYTE, 8).

main() ->
	%% Use packet 2 as we mostly want to send integers with 16 bits
    Port = open_port({spawn, "./naive_c_port"}, [{packet, 2}]),
	List = utils:parse(),

	send_list(Port, List),
	receive_solution(Port).

send_list(Port, [Head|Rest]) ->
	Port ! {self(), {command, encode(Head)}},
	send_list(Port, Rest);
send_list(Port, []) ->
	Port ! {self(), {command, encode(0)}}.

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