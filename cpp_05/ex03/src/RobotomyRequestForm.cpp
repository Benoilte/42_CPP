#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy_Request", m_signatureGrade, m_executionGrade),
	m_target("noTarget")
{
    /*Constructor*/
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &t_src) :
	AForm(t_src),
	m_target(t_src.m_target)
{
	/* Copy Constructor*/
}

RobotomyRequestForm::RobotomyRequestForm(const std::string t_target) :
	AForm("Robotomy_Request", m_signatureGrade, m_executionGrade),
	m_target(t_target)
{
	/* Parametrized Constructor*/
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	/*Destructor*/
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &t_rhs)
{
	if (this != &t_rhs)
		AForm::operator=(t_rhs);

	return *this;
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return m_target;
}

/*
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
*/

void RobotomyRequestForm::execute(Bureaucrat &t_executor) const
{
	beExectuted(t_executor, *this);
	std::cout << "Brrrrrrrrrr Brrrrrrrr" << std::endl;
	srand(time(NULL));
  	if (rand() % 2)
		std::cout << m_target  << " has been robotomized successfully" << std::endl;
	else
		std::cout << m_target  << " robotomy failed" << std::endl;
}

// std::ostream& operator<<(std::ostream &t_out, RobotomyRequestForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out;
// }
