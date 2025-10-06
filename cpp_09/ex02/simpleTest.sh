#!/bin/sh

DEF_COLOR="\033[0;39m"
RED="\033[0;91m"
GREEN="\033[0;92m"
YELLOW="\033[0;93m"

echo $GREEN"OK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 1 2 3)

echo

echo $GREEN"OK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 "42 83" 3)

echo

echo $GREEN"OK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 42 2147483647 83 3)

echo

echo $GREEN"OK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 42 21 8 83 3)

echo

echo $GREEN"OK "$DEF_COLOR 
(set -o xtrace;  ./PmergeMe 1 2 3 3)

echo

echo $GREEN"OK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 "42 3 83" 3)

echo

echo $RED"NOK "$DEF_COLOR 
(set -o xtrace;  ./PmergeMe -1 2 3)

echo

echo $RED"NOK "$DEF_COLOR 
(set -o xtrace;  ./PmergeMe 1 2 a 3)

echo

echo $RED"NOK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 "42 a 83" 3)

echo

echo $RED"NOK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 42 2147483648 83 3)

echo

echo $RED"NOK "$DEF_COLOR 
(set -o xtrace; ./PmergeMe 8 7 42 214748364843567 83 3)
