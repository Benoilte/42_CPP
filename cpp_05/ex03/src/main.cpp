#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./nightmareOffices 1': Test and display three different form" << std::endl;
	std::cout << "'./nightmareOffices 2': Test Shrubbery Creation Form" << std::endl;
	std::cout << "'./nightmareOffices 3': Test Robotomy Request Form" << std::endl;
	std::cout << "'./nightmareOffices 4': Test Presidential Pardon Form" << std::endl;
	std::cout << "'./nightmareOffices 5': Test Shrubbery Creation Form failed" << std::endl;
	std::cout << "'./nightmareOffices 6': Test Intern job" << std::endl;
}

void test1(void)
{
	std::cout << "test 1:" << std::endl;

	AForm	*form;
	Intern someRandomIntern;

	std::cout << YELLOW << "Intern create a Shrubbery Creation Form with target 'home'" << RESET << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << *form << std::endl;
	delete form;

	std::cout << YELLOW << "Instantiate a Robotomy Request Form with target 'bender'" << RESET << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "tmp");
	std::cout << *form << std::endl;
	delete form;

	std::cout << YELLOW << "Instantiate a Presidential Pardon Form with target 'tmp'" << RESET << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "bender");
	std::cout << *form << std::endl;
	delete form;
}

void test2(void)
{
	std::cout << "test 2:\n" << std::endl;

	AForm	*form;
	Intern	someRandomIntern;

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
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << *form << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Ben try to sign form 'Shrubbery Creation Form'" << RESET << std::endl;
	ben.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Shrubbery Creation Form'" << RESET << std::endl;
	joe.executeForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to sign form 'Shrubbery Creation Form'" << RESET << std::endl;
	yan.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to execute form 'Shrubbery Creation Form'" << RESET << std::endl;
	yan.executeForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Shrubbery Creation Form'" << RESET << std::endl;
	joe.executeForm(*form);
	std::cout << std::endl;

	delete form;
}

void test3(void)
{
	std::cout << "test 3:\n" << std::endl;

	AForm	*form;
	Intern	someRandomIntern;

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
	form = someRandomIntern.makeForm("robotomy request", "tmp");
	std::cout << *form << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Ben try to sign form 'Robotomy Request Form'" << RESET << std::endl;
	ben.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Robotomy Request Form'" << RESET << std::endl;
	joe.executeForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to sign form 'Robotomy Request Form'" << RESET << std::endl;
	yan.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to execute form 'Robotomy Request Form'" << RESET << std::endl;
	yan.executeForm(*form);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		srand(time(NULL));
  		sleep((rand() % 2) + 1);
		std::cout << CYAN << "Joe try to execute form 'Robotomy Request Form'" << RESET << std::endl;
		joe.executeForm(*form);
		std::cout << std::endl;
	}

	delete form;
}

void test4(void)
{
	std::cout << "test 4:\n" << std::endl;

	AForm	*form;
	Intern	someRandomIntern;

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
	form = someRandomIntern.makeForm("presidential pardon", "tmp");
	std::cout << *form << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Ben try to sign form 'Presidential Pardon Form'" << RESET << std::endl;
	ben.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Presidential Pardon Form'" << RESET << std::endl;
	joe.executeForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to sign form 'Presidential Pardon Form'" << RESET << std::endl;
	yan.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Yan try to execute form 'Presidential Pardon Form'" << RESET << std::endl;
	yan.executeForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe try to execute form 'Presidential Pardon Form'" << RESET << std::endl;
	joe.executeForm(*form);
	std::cout << std::endl;

	delete form;
}

void test5(void)
{
	std::cout << "test 5:\n" << std::endl;

	AForm	*form;
	Intern	someRandomIntern;

	std::cout << YELLOW << "Instantiate a bureaucrat 'Joe' with grade 8" << RESET << std::endl;
	Bureaucrat	joe("Joe", 8);
	std::cout << joe << std::endl;

	std::cout << YELLOW << "Instantiate a Shrubbery Creation Form with target 'fail'" << RESET << std::endl;
	std::cout << CYAN << "First You should create a 'fail_shrubbery' folder ( make fclean; mkdir fail_shrubbery; make )" << RESET << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "fail");
	std::cout << *form << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Joe sign the Form'" << RESET << std::endl;
	joe.signForm(*form);
	std::cout << std::endl;

	std::cout << YELLOW << "Joe execute the Form'" << RESET << std::endl;
	joe.executeForm(*form);
	std::cout << std::endl;

	delete form;
}

void test6(void)
{
	std::cout << "test 6:\n" << std::endl;

	Intern someRandomIntern;
	AForm* scf;
	AForm* rrf;
	AForm* ppf;
	AForm* unexisting;

	std::cout << YELLOW << "Intern create a shrubbery creation form with Bender as target'" << RESET << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *scf << std::endl;
	std::cout << std::endl;
	delete scf;

	std::cout << YELLOW << "Intern create a robotomy request form with Bender as target'" << RESET << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	std::cout << std::endl;
	delete rrf;

	std::cout << YELLOW << "Intern create a presidential pardon form with Bender as target'" << RESET << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *ppf << std::endl;
	std::cout << std::endl;
	delete ppf;

	std::cout << YELLOW << "Intern create an unexisting form with Bender as target'" << RESET << std::endl;
	unexisting = someRandomIntern.makeForm("unexisting", "Bender");
	std::cout << *unexisting << std::endl;
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

				case '6':
					test6();
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
