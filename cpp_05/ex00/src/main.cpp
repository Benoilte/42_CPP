#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./nightmareOffices 1': Throw Too high exception with constructor" << std::endl;
	std::cout << "'./nightmareOffices 2': Throw Too high exception with increment function" << std::endl;
	std::cout << "'./nightmareOffices 3': Throw Too low exception with constructor" << std::endl;
	std::cout << "'./nightmareOffices 4': Throw Too low exception with decrement function" << std::endl;
	std::cout << "'./nightmareOffices 5': Test working case function without throwing exception" << std::endl;
}

void test1(void)
{
	std::cout << "test 1:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat with grade 0" << RESET << std::endl;
	Bureaucrat	yan("yan", 0);
}

void test2(void)
{
	std::cout << "test 2:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'yan' with grade 1" << RESET << std::endl;
	Bureaucrat	yan("yan", 1);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "increment yan's grade by 1" << RESET << std::endl;
	yan.incrementGrade();
	std::cout << yan << std::endl;
}

void test3(void)
{
	std::cout << "test 3:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat with grade 151" << RESET << std::endl;
	Bureaucrat	tom("tom", 151);
}

void test4(void)
{
	std::cout << "test 4:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'yan' with grade 150" << RESET << std::endl;
	Bureaucrat	yan("yan", 150);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "decrement yan's grade by 1" << RESET << std::endl;
	yan.decrementGrade();
	std::cout << yan << std::endl;
}

void test5(void)
{
	std::cout << "test 5:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'joe' with grade 42" << RESET << std::endl;
	Bureaucrat	joe("joe", 42);
	std::cout << joe << std::endl;
	std::cout << YELLOW << "increment joe's grade by 2" << RESET << std::endl;
	joe.incrementGrade();
	joe.incrementGrade();
	std::cout << joe << std::endl;
	std::cout << YELLOW << "decrement joe's grade by 1" << RESET << std::endl;
	joe.decrementGrade();
	std::cout << joe << std::endl;
}

int	main(int argc, char **argv)
{
	if ((argc == 2) && ((std::string)argv[1]).size() == 1)
	{
		try
		{
			switch (argv[1][0])
			{
				case '1':
					test1();
					break;

				case '2':
					test2();
					break;

				case '3':
					test3();
					break;

				case '4':
					test4();
					break;

				case '5':
					test5();
					break;

				default:
					help();
					break;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		help();
	return (0);
}
