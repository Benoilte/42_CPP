#include "ShrubberyCreationForm.hpp"

int	ShrubberyCreationForm::m_signatureGrade = 145;
int	ShrubberyCreationForm::m_executionGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm()
{
    /*Constructor*/
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &t_src)
{
	*this = t_src;

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string t_target) : m_target(t_target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	/*Destructor*/
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &t_rhs)
{
	if (this != &t_rhs)
		AForm::operator=(t_rhs);
	
	return *this;
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return m_target;
}

// std::ostream& operator<<(std::ostream &t_out, ShrubberyCreationForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out; 
// }