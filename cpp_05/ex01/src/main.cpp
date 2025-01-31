#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./nightmareOffices 1': Instatiate form with too high required grade to sign" << std::endl;
	std::cout << "'./nightmareOffices 2': Instatiate form with too low required grade to sign" << std::endl;
	std::cout << "'./nightmareOffices 3': Instatiate form with too high required grade to execute" << std::endl;
	std::cout << "'./nightmareOffices 4': Instatiate form with too low required grade to execute" << std::endl;
	std::cout << "'./nightmareOffices 5': Throw Too low exception to signed a form" << std::endl;
	std::cout << "'./nightmareOffices 6': Throw Too low exception to execute a form" << std::endl;
	std::cout << "'./nightmareOffices 7': Test working case function without throwing exception" << std::endl;
}

void test1(void)
{
	std::cout << "test 1:" << std::endl;

	std::cout << YELLOW << "Instantiate a form with required grade to sign at 0" << RESET << std::endl;
	Form	form("test", 0, 42);
}

void test2(void)
{
	std::cout << "test 2:" << std::endl;

	std::cout << YELLOW << "Instantiate a form with required grade to sign at 151" << RESET << std::endl;
	Form	form("test", 151, 42);
}

void test3(void)
{
	std::cout << "test 3:" << std::endl;

	std::cout << YELLOW << "Instantiate a form with required grade to execute at 0" << RESET << std::endl;
	Form	form("test", 42, 0);
}

void test4(void)
{
	std::cout << "test 4:" << std::endl;

	std::cout << YELLOW << "Instantiate a form with required grade to execute at 151" << RESET << std::endl;
	Form	form("test", 42, 151);
}

void test5(void)
{
	std::cout << "test 5:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 42" << RESET << std::endl;
	Bureaucrat	yan("Yan", 42);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "Instantiate a Form 'A' with a signing requirement grade of 24" << RESET << std::endl;
	Form	formA("A", 24, 29);
	std::cout << formA << std::endl;
	std::cout << YELLOW << "Yan try to sign form 'A'" << RESET << std::endl;
	yan.signForm(formA);
	std::cout << YELLOW << "Display Form 'A' (it should not be signed)" << RESET << std::endl;
	std::cout << formA << std::endl;
}

void test6(void)
{
	std::cout << "test 6:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 42" << RESET << std::endl;
	Bureaucrat	yan("Yan", 42);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "Instantiate a Form 'A' with an execution requirement grade of 29" << RESET << std::endl;
	Form	formA("A", 24, 29);
	std::cout << formA << std::endl;
	std::cout << YELLOW << "Yan try to execute form 'A'" << RESET << std::endl;
	yan.executeForm(formA);
	std::cout << YELLOW << "Display Form 'A' (it should not be signed)" << RESET << std::endl;
	std::cout << formA << std::endl;
}

void test7(void)
{
	std::cout << "test 7:" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 20" << RESET << std::endl;
	Bureaucrat	yan("Yan", 20);
	std::cout << yan << std::endl;
	std::cout << YELLOW << "Instantiate a Form 'A' with a signing requirement grade of 24 and an execution requirement grade of 29" << RESET << std::endl;
	Form	formA("A", 24, 29);
	std::cout << formA << std::endl;
	std::cout << YELLOW << "Yan try to sign form 'A'" << RESET << std::endl;
	yan.signForm(formA);
	std::cout << YELLOW << "Yan try to execute form 'A'" << RESET << std::endl;
	yan.executeForm(formA);
	std::cout << YELLOW << "Display Form 'A' (it should be signed)" << RESET << std::endl;
	std::cout << formA << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 25" << RESET << std::endl;
	Bureaucrat	joe("Joe", 25);
	std::cout << joe << std::endl;
	std::cout << YELLOW << "increment joe's grade by 1" << RESET << std::endl;
	joe.incrementGrade();
	std::cout << joe << std::endl;
	std::cout << YELLOW << "Instantiate a Form 'B' with a signing requirement grade of 24 and an execution requirement grade of 29" << RESET << std::endl;
	Form	formB("B", 24, 29);
	std::cout << formB << std::endl;
	std::cout << YELLOW << "Joe try to sign form 'B'" << RESET << std::endl;
	joe.signForm(formB);
	std::cout << YELLOW << "Joe try to execute form 'B'" << RESET << std::endl;
	joe.executeForm(formB);
	std::cout << YELLOW << "Display Form 'B' (it should be signed)" << RESET << std::endl;
	std::cout << formB << std::endl;
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

				case '6':
					test6();
					break;

				case '7':
					test7();
					break;

				default:
					help();
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
