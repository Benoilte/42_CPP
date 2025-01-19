#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./nightmareOffices 1': Throw Too low exception to signed a form" << std::endl;
	std::cout << "'./nightmareOffices 2': Throw Too low exception to execute a form" << std::endl;
	// std::cout << "'./nightmareOffices 3': Throw Too low exception with constructor" << std::endl;
	// std::cout << "'./nightmareOffices 4': Throw Too low exception with decrement function" << std::endl;
}

void test1(void)
{
	std::cout << "test 1:" << std::endl;
	
	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 42" << RESET << std::endl;
	Bureaucrat	yan("Yan", 42);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "Instantiate a Form 'A' with a requirement grade of 24 to be signed" << RESET << std::endl;
	Form	formA("A", 24, 29);
	std::cout << formA << std::endl;
	std::cout << YELLOW << "Yan try to sign form 'A'" << RESET << std::endl;
	yan.signForm(formA);
	std::cout << YELLOW << "Display Form 'A' stay unchanged" << RESET << std::endl;
	std::cout << formA << std::endl;
}

void test2(void)
{
	std::cout << "test 2:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 42" << RESET << std::endl;
	Bureaucrat	yan("Yan", 42);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "Instantiate a Form 'A' with a requirement grade of 29 to be executed" << RESET << std::endl;
	Form	formA("A", 24, 29);
	std::cout << formA << std::endl;
	std::cout << YELLOW << "Yan try to execute form 'A'" << RESET << std::endl;
	yan.signForm(formA);
	std::cout << formA << std::endl;
}

// void test3(void)
// {
// 	std::cout << "test 3:" << std::endl;

// 	std::cout << YELLOW << "Instantiate a bureaucrat with grade 151" << RESET << std::endl;
// 	Bureaucrat	tom("tom", 151);
// }

// void test4(void)
// {
// 	std::cout << "test 4:" << std::endl;

// 	std::cout << YELLOW << "Instantiate a bureaucrat 'yan' with grade 150" << RESET << std::endl;
// 	Bureaucrat	yan("yan", 150);
// 	std::cout << yan << std::endl;
// 	std::cout << YELLOW << "decrement yan's grade by 1" << RESET << std::endl;
// 	yan.decrementGrade();
// 	std::cout << yan << std::endl;
// }

// void test5(void)
// {
// 	std::cout << "test 5:" << std::endl;
	
// 	std::cout << YELLOW << "Instantiate a bureaucrat 'joe' with grade 42" << RESET << std::endl;
// 	Bureaucrat	joe("joe", 42);
// 	std::cout << joe << std::endl;
// 	std::cout << YELLOW << "increment joe's grade by 2" << RESET << std::endl;
// 	joe.incrementGrade();
// 	joe.incrementGrade();
// 	std::cout << joe << std::endl;
// 	std::cout << YELLOW << "decrement joe's grade by 1" << RESET << std::endl;
// 	joe.decrementGrade();
// 	std::cout << joe << std::endl;
// }

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

				// case '3':
				// 	test3();
				// 	break;

				// case '4':
				// 	test4();
				// 	break;

				// case '5':
				// 	test5();
				// 	break;

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
