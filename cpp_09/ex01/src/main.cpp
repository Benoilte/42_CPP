#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN rpn((std::string(argv[1])));
		std::cout << rpn.compute() << std::endl;
	}
	else
		std::cout << "ERROR" << std::endl;

	return (0);
}
