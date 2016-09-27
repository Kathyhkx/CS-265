#!/bin/sh

MARKOVS="markov++-array-list markov++-array-vector \
	markov++-deque-list markov++-deque-vector \
	markov++-list-list markov++-list-vector \
	markov++-vector-list markov++-vector-vector"
TEXT="markov_test.txt"

for markov in $MARKOVS; do
	echo $markov
	time ./$markov < $TEXT > /dev/null
done
