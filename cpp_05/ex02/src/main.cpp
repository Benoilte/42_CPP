#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./nightmareOffices 1': Test and display three different form" << std::endl;
	std::cout << "'./nightmareOffices 2': Test Shrubbery Creation Form" << std::endl;
	std::cout << "'./nightmareOffices 3': Test Robotomy Request Form" << std::endl;
	std::cout << "'./nightmareOffices 4': Test Presidential Pardon Form" << std::endl;
	std::cout << "'./nightmareOffices 5': Test Shrubbery Creation Form failed" << std::endl;
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

	// 145, exec 137
	std::cout << YELLOW << "Instantiate a bureaucrat 'Ben' with grade 148" << RESET << std::endl;
	Bureaucrat	ben("Ben", 148);
	std::cout << ben << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 140" << RESET << std::endl;
	Bureaucrat	yan("Yan", 140);
	std::cout << yan << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 138" << RESET << std::endl;
	Bureaucrat	joe("Joe", 138);
	std::cout << joe << std::endl;
	std::cout << YELLOW << "increment joe's grade by 1" << RESET << std::endl;
	joe.incrementGrade();
	std::cout << joe << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a Shrubbery Creation Form with target 'home'" << RESET << std::endl;
	ShrubberyCreationForm	shrub("home");
	std::cout << shrub << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Ben try to sign form 'Shrubbery Creation Form'" << RESET << std::endl;
	ben.signForm(shrub);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Shrubbery Creation Form'" << RESET << std::endl;
	joe.executeForm(shrub);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to sign form 'Shrubbery Creation Form'" << RESET << std::endl;
	yan.signForm(shrub);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to execute form 'Shrubbery Creation Form'" << RESET << std::endl;
	yan.executeForm(shrub);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Shrubbery Creation Form'" << RESET << std::endl;
	joe.executeForm(shrub);
	std::cout << std::endl;
}

void test3(void)
{
	std::cout << "test 3:\n" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Ben' with grade 84" << RESET << std::endl;
	Bureaucrat	ben("Ben", 84);
	std::cout << ben << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Yan' with grade 70" << RESET << std::endl;
	Bureaucrat	yan("Yan", 70);
	std::cout << yan << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 46" << RESET << std::endl;
	Bureaucrat	joe("Joe", 46);
	std::cout << joe << std::endl;
	std::cout << YELLOW << "increment joe's grade by 1" << RESET << std::endl;
	joe.incrementGrade();
	std::cout << joe << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Instantiate a Robotomy Request Form with target 'tmp'" << RESET << std::endl;
	RobotomyRequestForm	rob("tmp");
	std::cout << rob << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Ben try to sign form 'Robotomy Request Form'" << RESET << std::endl;
	ben.signForm(rob);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Robotomy Request Form'" << RESET << std::endl;
	joe.executeForm(rob);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to sign form 'Robotomy Request Form'" << RESET << std::endl;
	yan.signForm(rob);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to execute form 'Robotomy Request Form'" << RESET << std::endl;
	yan.executeForm(rob);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		srand(time(NULL));
  		sleep((rand() % 2) + 1);
		std::cout << CYAN << "Joe try to execute form 'Robotomy Request Form'" << RESET << std::endl;
		joe.executeForm(rob);
		std::cout << std::endl;
	}

}

void test4(void)
{
	std::cout << "test 4:\n" << std::endl;

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

void test5(void)
{
	std::cout << "test 5:\n" << std::endl;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 8" << RESET << std::endl;
	Bureaucrat	joe("Joe", 8);
	std::cout << joe << std::endl;

	std::cout << YELLOW << "Instantiate a Shrubbery Creation Form with target 'fail'" << RESET << std::endl;
	std::cout << CYAN << "First You should create a 'fail_shrubbery' folder ( make fclean; mkdir fail_shrubbery; make )" << RESET << std::endl;
	ShrubberyCreationForm	shrub("fail");
	std::cout << shrub << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Joe sign the Form'" << RESET << std::endl;
	joe.signForm(shrub);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe execute the Form'" << RESET << std::endl;
	joe.executeForm(shrub);
	std::cout << std::endl;
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
