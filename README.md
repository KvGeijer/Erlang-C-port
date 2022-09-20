## Interfacing Erlang and C ##

This is just a test to see how an Erlang program can communicate with a program written in C (or really any language). This is done through communicating over a port and is described [here](https://www.erlang.org/doc/tutorial/c_port.html), but it can also be done by setting up a [C-node](https://www.erlang.org/doc/tutorial/cnode.html).

# Problem selection

The complexity of the problem should be quite low, but it would be fun to be able to analyze some perforamnce issues. Therefore I chose the triple sum problem from Advent of Code 2020 [day 1, part 2](https://adventofcode.com/2020/day/1) (part 2 is hidden until part 1 is complete, which is the same problem but for a sum of two integers). The problem is that we have a list of integers, and we should find a combination of three list items which sum to a specific number (here 2020).

# Implementations

I will compare several implementations:
* Naive triple loop in Erlang through list comprehension,
* Erlang communicating with same solution written in C,
* Erlang communicating with smart solution in C utilizing that the list can be sorted.