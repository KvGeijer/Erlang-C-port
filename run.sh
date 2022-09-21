#!/bin/bash

erl -noshell -s make all -s init stop
cd ebin
cat ../$2 | time erl -noshell -s $1 main -s init stop
cd ..