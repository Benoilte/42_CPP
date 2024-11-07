#!/bin/bash

DEF_COLOR="\033[0;39m"
RED="\033[0;91m"
GREEN="\033[0;92m"
YELLOW="\033[0;93m"

echo -e $YELLOW"\nTest megaphone program without argument\n"
./../megaphone > test.txt
if cmp -s test.txt expected/megaphone_whithout_arg.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: * LOUD AND UNBEARABLE FEEDBACK NOISE *"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi

echo -e $YELLOW"\nTest megaphone program with one string\n"
./../megaphone "shhhhh... I think the students are asleep..." > test.txt
if cmp -s test.txt expected/one_string.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: $(cat expected/one_string.txt)"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi

echo -e $YELLOW"\nTest megaphone program with several argument\n"
./../megaphone Damnit " ! " "Sorry students, I thought this thing was off." > test.txt
if cmp -s test.txt expected/several_arg.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: $(cat expected/several_arg.txt)"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi

echo -e $YELLOW"\nTest megaphone program with two args and number\n"
./../megaphone 1a2b3c "Boum4" > test.txt
if cmp -s test.txt expected/two_args_and_number.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: $(cat expected/two_args_and_number.txt)"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi

echo -e $YELLOW"\nTest megaphone program with one letter arg\n"
./../megaphone h > test.txt
if cmp -s test.txt expected/one_letter_arg.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: $(cat expected/one_letter_arg.txt)"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi

echo -e $YELLOW"\nTest megaphone program with one number arg\n"
./../megaphone 42 > test.txt
if cmp -s test.txt expected/one_number_arg.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: $(cat expected/one_number_arg.txt)"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi

echo -e $YELLOW"\nTest megaphone program with only space arg\n"
./../megaphone "    " > test.txt
if cmp -s test.txt expected/only_space_arg.txt
then
	echo -e $GREEN"SUCCESS"$DEF_COLOR
else
	echo -e $RED"FAILURE"$DEF_COLOR
	echo -e "Expected: $(cat expected/only_space_arg.txt)"$DEF_COLOR
	echo -e "get     : $(cat test.txt)"$DEF_COLOR
fi
rm test.txt
