#include "file.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Wrong number of argument - expected: ./sed <filename> <str1> <str2>" << std::endl;
	(void)argv;
	return (0);
}

