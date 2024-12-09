#include "File.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of argument - expected: ./sed <filename> <str1> <str2>" << std::endl;
		return 1;
	}

	File	test(argv[1]);
	test.sed(argv[2], argv[3]);
	return (0);
}
