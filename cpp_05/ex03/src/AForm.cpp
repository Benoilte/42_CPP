#include "AForm.hpp"

AForm::AForm() :
	m_name("default"),
	m_isSigned(false),
	m_requireGradeToSigne(42),
	m_requireGradeToExecute(42)
{
    /*Constructor*/
}

AForm::AForm(const AForm &t_src) :
	m_name(t_src.getName()),
	m_isSigned(t_src.getIsSigned()),
	m_requireGradeToSigne(t_src.getRequireGradeToSigne()),
	m_requireGradeToExecute(t_src.getRequireGradeToExecute())
{
	/*Copy Constructor*/
}

AForm::AForm(const std::string t_name, int t_gradeToSigned, int t_gradeToExecute) :
	m_name(t_name),
	m_isSigned(false),
	m_requireGradeToSigne(t_gradeToSigned),
	m_requireGradeToExecute(t_gradeToExecute)
{
	/*Parametrized Constructor*/
}

AForm::~AForm()
{
	/*Destructor*/
}

AForm& AForm::operator=(const AForm &t_rhs)
{
	if (this != &t_rhs)
		this->m_isSigned = t_rhs.getIsSigned();

	return *this;
}

const std::string AForm::getName(void) const { return m_name; }

int AForm::getIsSigned(void) const { return m_isSigned; }

int AForm::getRequireGradeToSigne(void) const { return m_requireGradeToSigne; }

int AForm::getRequireGradeToExecute(void) const { return m_requireGradeToExecute; }

void AForm::beSigned(Bureaucrat &t_signer)
{
	if (t_signer.getGrade() <= getRequireGradeToSigne()) {
		m_isSigned = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::beExectuted(Bureaucrat &t_executor, AForm const &t_form) const
{
	if (t_executor.getGrade() <= getRequireGradeToExecute()) {
		if (t_form.getIsSigned()) {
			return ;
		} else {
			throw AForm::FormIsNotSigned();
		}
	} else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &t_out, AForm const &t_rhs)
{
	std::string verboseSigned = t_rhs.getIsSigned() ? "Yes" : "No";

	t_out	<< "Form: "
			<< t_rhs.getName()
			<< " - Signature requirement: "
			<< t_rhs.getRequireGradeToSigne()
			<< " - Execution requirement: "
			<< t_rhs.getRequireGradeToExecute()
			<< " - Form signed: "
			<< verboseSigned;
	return t_out;
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Error: Bureaucrat's grade is too low";
}

const char	*AForm::FormIsNotSigned::what() const throw()
{
	return "Error: Form is not signed";
}
