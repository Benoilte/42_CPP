#include "PresidentialPardonForm.hpp"

int	PresidentialPardonForm::m_signatureGrade = 25;
int	PresidentialPardonForm::m_executionGrade = 5;

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential_Pardon", m_signatureGrade, m_executionGrade),
	m_target("noTarget")
{
    /*Constructor*/
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &t_src) :
	AForm(t_src),
	m_target(t_src.m_target)
{
	/* Copy Constructor*/
}

PresidentialPardonForm::PresidentialPardonForm(const std::string t_target) :
	AForm("Presidential_Pardon", m_signatureGrade, m_executionGrade),
	m_target(t_target)
{
	/* Parametrized Constructor*/
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	/*Destructor*/
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &t_rhs)
{
	if (this != &t_rhs)
		AForm::operator=(t_rhs);

	return *this;
}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return m_target;
}

void PresidentialPardonForm::execute(Bureaucrat &t_executor) const
{
	beExectuted(t_executor, *this);
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// std::ostream& operator<<(std::ostream &t_out, PresidentialPardonForm const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out;
// }
