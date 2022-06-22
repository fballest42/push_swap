#!/bin/sh
for i in {1. .50}
do
#echo test $i
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
#echo $ARG
./push_swap $ARG | wc -l
#echo
done
