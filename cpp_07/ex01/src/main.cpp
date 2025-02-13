#include "utils.hpp"
#include <iostream>

void	addTwo(int &n)
{
	n += 2;
}

void	displayInt(int const &n)
{
	std::cout << n << std::endl;
}

void	defineLetter(char const &c)
{
	std::string	vowels = "aeiouyAEIOUY";

	if ((vowels.find(c, 0) != std::string::npos))
		std::cout << c << ": vowel" << std::endl;
	else if (std::isalpha(c))
		std::cout << c << ": consonant" << std::endl;
}

void	RotateLowercase(char &c)
{
	char min = 'a', max = 'z';

	if (std::islower(c))
		c = max - (c - min);
}

void	testIntArray()
{
	int	intArray[3] = {2, 4, 6};
	size_t	length  = 3;

	std::cout << CYAN << "Test with array of int and function to add 2" << RESET << std::endl;
	for (size_t i = 0; i < length; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	iter(intArray, length, addTwo);
	std::cout << YELLOW << "Function iter is called" << RESET << std::endl;
	for (size_t i = 0; i < length; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;	
}

void	testConstIntArray()
{
	int	const intArray[3] = {2, 4, 6};
	size_t	length  = 3;

	std::cout << CYAN << "Test with array of const int and function to display element" << RESET << std::endl;
	for (size_t i = 0; i < length; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << YELLOW << "Function iter is called" << RESET << std::endl;
	iter(intArray, length, displayInt);
}

void	testConstAlphabet()
{
	char const	intArray[27] = {'a', 'b', 'c', 'd', 'E', 'F', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ';'};
	size_t	length  = 27;

	std::cout << CYAN << "Test with array of const char and function to display if letter is consonant or vowel" << RESET << std::endl;
	for (size_t i = 0; i < length; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << YELLOW << "Function iter is called" << RESET << std::endl;
	iter(intArray, length, defineLetter);
}

void	testLowercaseRotate()
{
	char	intArray[8] = {'a', 'b', 'c', 'A', ';', 'x', 'y', 'z'};
	size_t	length  = 8;

	std::cout << CYAN << "Test with array of char and function to rotate lower case letter" << RESET << std::endl;
	for (size_t i = 0; i < length; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << YELLOW << "Function iter is called" << RESET << std::endl;
	iter(intArray, length, RotateLowercase);
	for (size_t i = 0; i < length; i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
}

int	main(void)
{
	testIntArray();
	std::cout << std::endl;
	testConstIntArray();
	std::cout << std::endl;
	testConstAlphabet();
	std::cout << std::endl;
	testLowercaseRotate();
	return (0);
}

