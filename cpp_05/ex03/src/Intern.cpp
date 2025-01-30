#include "Intern.hpp"

Intern::Intern()
{
    /*Constructor*/
}

Intern::Intern(const Intern &t_src)
{
	*this = t_src;

	return ;
}

Intern::~Intern()
{
	/*Destructor*/
}

Intern& Intern::operator=(const Intern &t_rhs)
{
	(void)t_rhs;

	return *this;
}

AForm* Intern::makeForm(std::string t_formName, std::string t_target)
{
	typedef AForm	*(Intern::*makePtr)(std::string);
	makePtr	createForm[3]	= {&Intern::makePresidentialPardon, &Intern::makeRobotomyRequest, &Intern::makeShrubberyCreation};
	// AForm	*(Intern::*createForm[3])(std::string)	= {&Intern::makePresidentialPardon, &Intern::makeRobotomyRequest, &Intern::makeShrubberyCreation};
	const std::string   existingFormName[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (t_formName == existingFormName[i])
		{
			std::cout << "Intern creates " << t_formName << " form" << std::endl;
			return (this->*createForm[i])(t_target);
		}
	}
	std::cout << "You try to create an unexisting form" << std::endl;
	return 0;
}

AForm* Intern::makePresidentialPardon(std::string t_target)
{
	return (new PresidentialPardonForm(t_target));
}

AForm* Intern::makeRobotomyRequest(std::string t_target)
{
	return (new RobotomyRequestForm(t_target));
}

AForm* Intern::makeShrubberyCreation(std::string t_target)
{
	return (new ShrubberyCreationForm(t_target));
}
