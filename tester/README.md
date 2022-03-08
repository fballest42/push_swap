# push_swap
42 project Push_Swap programs to check and sort a list of integers

Para número aleatorios
ARG=$(ruby -e "puts (0..100).to_a.shuffle.join(' ')");  ./push_swap $ARG | ./checker $ARG