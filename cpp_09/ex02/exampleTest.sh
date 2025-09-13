#!/bin/sh

DEF_COLOR="\033[0;39m"
RED="\033[0;91m"
GREEN="\033[0;92m"
YELLOW="\033[0;93m"

echo $GREEN"OK "$DEF_COLOR
(set -o xtrace; ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7)
