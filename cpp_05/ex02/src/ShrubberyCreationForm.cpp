#include "ShrubberyCreationForm.hpp"

int	ShrubberyCreationForm::m_signatureGrade = 145;
int	ShrubberyCreationForm::m_executionGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery_Creation", m_signatureGrade, m_executionGrade),
	m_target("noTarget")
{
    /*Constructor*/
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &t_src) :
	AForm(t_src),
	m_target(t_src.m_target)
{
	/* Copy Constructor*/
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string t_target) :
	AForm("Shrubbery_Creation", m_signatureGrade, m_executionGrade),
	m_target(t_target)
{
	/* Parametrized Constructor*/
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

void ShrubberyCreationForm::execute(Bureaucrat &t_executor) const
{
	(void)t_executor;
}

// std::ostream& operator<<(std::ostream &t_out, ShrubberyCreationForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out;
// }
