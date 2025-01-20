#include "RobotomyRequestForm.hpp"

int	RobotomyRequestForm::m_signatureGrade = 72;
int	RobotomyRequestForm::m_executionGrade = 45;

RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("noTarget_shrubbery", m_signatureGrade, m_signatureGrade), 
	m_target("noTarget")
{
    /*Constructor*/
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &t_src)
{
	*this = t_src;

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string t_target) : m_target(t_target)
{
	
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

// std::ostream& operator<<(std::ostream &t_out, RobotomyRequestForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out; 
// }