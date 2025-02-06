#include "ScalarConverter.hpp"
#include <iostream>

void	testDefault(void)
{
	std::cout << "Implement default test" << std::endl;
}

int	main(int argc, char **argv)
{
	// ScalarConverter sc;
	std::string input;

	switch (argc)
	{
		case 1:
			testDefault();
			break;
	
		case 2:
			input = argv[1];
			ScalarConverter::convert(input);
			break;
	
		default:
			std::cout << "Available command: " << std::endl;
			std::cout << "'./convert [+-][number] [[.][number][f]]'" << std::endl;
	}
	return (0);
}

