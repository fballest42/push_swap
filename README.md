# PUSH SWAP

### This is a 42 Cursus project that makes you create a program to sort a list of number using two stacks (a and b) and a few permited movements. You can find more information of this project in the subject in [English](Subject/en.subject.pdf) o [Spanish](Subject/es.subject.pdf).

## Inital stacks
#### Stack A contains a random amount of numbers of integers (negative or positive and with no duplicates).
#### Stack B is empty.

## Moves allowed are:
#### sa (swap a): Swap the first 2 elements at the top of stack a.
#### sb (swap b): Swap the first 2 elements at the top of stack b.
#### ss : sa and sb at the same time.
#### pa (push a): Take the first element at the top of b and put it at the top of a.
#### pb (push b): Take the first element at the top of a and put it at the top of b.
#### ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
#### rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
#### rr : ra and rb at the same time.
#### rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
#### rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
#### rrr : rra and rrb at the same time.

## How to work with it:
### If you want to run the program and introduce manually a few numbers:
##### make && ./push_swap 4 1 6 3 2 5
### If you want to run the program and introduce a list of number from an enviroment variable, and:
#### - you want to list the moves:
#### make && ARG="4 67 3 87 23"; ./push_swap $ARG
#### - you want to count the number of moves:
#### make && ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
#### - you want to check is your list of moves sort your list
#### make && ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG *
##### * You must know that the checker file is provided in the Subject, you have a Mac version and a Linux version. Here you will find the Mac version as "checker" cause is my natural developvment enviromet.
### You can use my test to check several set of numbers at the same time. All the modifications accepted in this test are explained in the comments of the file [my_test.sh](my_test.sh). Make any modification that you need and launch:
#### make && sh my_test.sh
### You have available a complex and slower test for push_swap project in the [Tester](Tester/) folder. It include a README to know how to work with it.

### Graded: According to the number of moves to sort 100 numbers and 500 numbers you will receive and score between 1 and 5. My algoritm gets 5 for 100 numbers and 3 for 500 numbers.

[![fballest's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl45d74de005409l9l5r3ozl6/project/2138660)](https://github.com/JaeSeoKim/badge42) 