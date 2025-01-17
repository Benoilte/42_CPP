#include "Bureaucrat.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Bureaucrat	joe("joe", 42);

	std::cout << joe << std::endl;
	joe.incrementGrade();
	joe.incrementGrade();
	std::cout << joe << std::endl;
	joe.decrementGrade();
	std::cout << joe << std::endl;

	try
	{
		Bureaucrat	yan("yan", 0);
		std::cout << yan << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	tom("tom", 151);
		std::cout << tom << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
