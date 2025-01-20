#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./nightmareOffices 1': Test and display three different form" << std::endl;
	std::cout << "'./nightmareOffices 2': Test Presidential Pardon Form" << std::endl;
	// std::cout << "'./nightmareOffices 3': Test working case function without throwing exception" << std::endl;
	// std::cout << "'./nightmareOffices 4': Throw Too low exception with decrement function" << std::endl;
}

void test1(void)
{
	std::cout << "test 1:" << std::endl;

	std::cout << YELLOW << "Instantiate a Shrubbery Creation Form with target 'home'" << RESET << std::endl;
	ShrubberyCreationForm	shrub("home");
	std::cout << shrub << std::endl;

	std::cout << YELLOW << "Instantiate a Robotomy Request Form with target 'bender'" << RESET << std::endl;
	RobotomyRequestForm	robReq("bender");
	std::cout << robReq << std::endl;

	std::cout << YELLOW << "Instantiate a Presidential Pardon Form with target 'tmp'" << RESET << std::endl;
	PresidentialPardonForm	pres("tmp");
	std::cout << pres << std::endl;
}

void test2(void)
{
	std::cout << "test 2:\n" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Ben' with grade 42" << RESET << std::endl;
	Bureaucrat	ben("Ben", 42);
	std::cout << ben << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 20" << RESET << std::endl;
	Bureaucrat	yan("Yan", 20);
	std::cout << yan << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 6" << RESET << std::endl;
	Bureaucrat	joe("Joe", 6);
	std::cout << joe << std::endl;
	std::cout << YELLOW << "increment joe's grade by 1" << RESET << std::endl;
	joe.incrementGrade();
	std::cout << joe << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a Presidential Pardon Form with target 'tmp'" << RESET << std::endl;
	PresidentialPardonForm	pres("tmp");
	std::cout << pres << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Ben try to sign form 'Presidential Pardon Form'" << RESET << std::endl;
	ben.signForm(pres);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Presidential Pardon Form'" << RESET << std::endl;
	joe.executeForm(pres);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to sign form 'Presidential Pardon Form'" << RESET << std::endl;
	yan.signForm(pres);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to execute form 'Presidential Pardon Form'" << RESET << std::endl;
	yan.executeForm(pres);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Presidential Pardon Form'" << RESET << std::endl;
	joe.executeForm(pres);
	std::cout << std::endl;

}

// void test3(void)
// {
// 	std::cout << "test 3:" << std::endl;

// 	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 20" << RESET << std::endl;
// 	Bureaucrat	yan("Yan", 20);
// 	std::cout << yan << std::endl;
// 	std::cout << YELLOW << "Instantiate a Form 'A' with a signing requirement grade of 24 and an execution requirement grade of 29" << RESET << std::endl;
// 	AForm	formA("A", 24, 29);
// 	std::cout << formA << std::endl;
// 	std::cout << YELLOW << "Yan try to sign form 'A'" << RESET << std::endl;
// 	yan.signForm(formA);
// 	std::cout << YELLOW << "Yan try to execute form 'A'" << RESET << std::endl;
// 	yan.executeForm(formA);
// 	std::cout << YELLOW << "Display Form 'A' (it should be signed)" << RESET << std::endl;
// 	std::cout << formA << std::endl;

// 	std::cout << std::endl;

// 	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 25" << RESET << std::endl;
// 	Bureaucrat	joe("Joe", 25);
// 	std::cout << joe << std::endl;
// 	std::cout << YELLOW << "increment joe's grade by 1" << RESET << std::endl;
// 	joe.incrementGrade();
// 	std::cout << joe << std::endl;
// 	std::cout << YELLOW << "Instantiate a Form 'B' with a signing requirement grade of 24 and an execution requirement grade of 29" << RESET << std::endl;
// 	AForm	formB("B", 24, 29);
// 	std::cout << formB << std::endl;
// 	std::cout << YELLOW << "Joe try to sign form 'B'" << RESET << std::endl;
// 	joe.signForm(formB);
// 	std::cout << YELLOW << "Joe try to execute form 'B'" << RESET << std::endl;
// 	joe.executeForm(formB);
// 	std::cout << YELLOW << "Display Form 'B' (it should be signed)" << RESET << std::endl;
// 	std::cout << formB << std::endl;
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
