#include <iostream>

int	main(void)
{
	std::string	str {"HI THIS IS BRAIN"};
	std::string *stringPTR {&str};
	std::string &stringREF {str};

	// Print memory adress of variable
	std::cout << "memory address of the str:\t\t" << &str << std::endl;
	std::cout << "memory address held by stringPTR:\t" << &stringPTR << std::endl;
	std::cout << "memory address held by stringREF:\t" << &stringREF << std::endl;
	// Print value of variable
	std::cout << "value of the str:\t\t\t" << str << std::endl;
	std::cout << "value pointed to by stringPTR:\t\t" << stringPTR << std::endl;
	std::cout << "value pointed to by stringREF:\t\t" << stringREF << std::endl;
	return (0);
}
