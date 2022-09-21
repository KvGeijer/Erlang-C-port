-module(utils).

-export([parse/0]).

-spec parse() -> [integer()].
parse() ->
    List = read_list(),
    lists:map(fun line_to_int/1, List).

%%%%%%%%%%%%%%%%%%%%%%
%% HELPER FUNCTIONS %%
%%%%%%%%%%%%%%%%%%%%%%

line_to_int(Line) ->
    list_to_integer(remove_newline(Line)).

remove_newline(String) ->
    lists:filter(fun(Char) -> Char /= $\n end, String).

read_list() ->
    case io:get_line("") of
        eof                 -> [];
        {error, _Reason}    -> [];
        Line                -> [Line | read_list()]
    end.