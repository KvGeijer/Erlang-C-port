#!/bin/bash

erl -noshell -s make all -s init stop
cd c_src
make
cd ../ebin
cat ../$2 | time erl -noshell -s $1 main -s init stop
cd ..