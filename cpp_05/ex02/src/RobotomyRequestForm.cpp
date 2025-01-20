#include "RobotomyRequestForm.hpp"

int	RobotomyRequestForm::m_signatureGrade = 72;
int	RobotomyRequestForm::m_executionGrade = 45;

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

void RobotomyRequestForm::execute(Bureaucrat &t_executor) const
{
	(void)t_executor;
}

// std::ostream& operator<<(std::ostream &t_out, RobotomyRequestForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out;
// }
