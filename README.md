## Interfacing Erlang and C ##

This is just a test to see how an Erlang program can communicate with a program written in C (or really any language). This can be done in several ways, for example:
* The first is through communicating over a port and is described [here](https://www.erlang.org/doc/tutorial/c_port.html),
* The second is using a NIF, which is like directly calling the C function in Erlang. Unsafe but fast and convienient. It is described [here](https://www.erlang.org/doc/tutorial/nif.html),
* A third option which we will not be exploring is setting up a [C-node](https://www.erlang.org/doc/tutorial/cnode.html). It creates a process which looks like an Erlang node to Erlang, but is really implemented in C.

# Problem selection

The complexity of the problem should be quite low, but it would be fun to be able to analyze some perforamnce issues. Therefore I chose the triple sum problem from Advent of Code 2020 [day 1, part 2](https://adventofcode.com/2020/day/1) (part 2 is hidden until part 1 is complete, which is the same problem but for a sum of two integers). The problem is that we have a list of integers, and we should find a combination of three list items which sum to a specific number (here 2020).

# Implementations

I will compare several implementations:
* Naive triple loop in Erlang through list comprehension,
* Erlang communicating with C over a port using a naive solution,
* Using a NIF in Erlang to use the naive C solution,
* Using a C NIF in Erlang with the smart solution.

It would be nice to get some real performance test here. But there data I have so far is not large enough to notice much difference.