#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Wrong number of argument - expected: ./harl <level> - Argument expected: DEBUG || INFO || WARNING || ERROR " << std::endl;
		return 1;
	}
	level = argv[1];
	if (level.empty())
		std::cout << "Your argument should not be empty - Argument expected: DEBUG || INFO || WARNING || ERROR " << std::endl;
	else
		harl.complain(argv[1]);
	return (0);
}

