#include "AForm.hpp"

AForm::AForm() :
	m_name("default"),
	m_isSigned(false),
	m_requireGradeToSigne(m_defaultGrade),
	m_requireGradeToExecute(m_defaultGrade)
{
    /*Constructor*/
}

AForm::AForm(const AForm &t_src) :
	m_name(t_src.getName()),
	m_isSigned(t_src.getIsSigned()),
	m_requireGradeToSigne(t_src.getRequireGradeToSigne()),
	m_requireGradeToExecute(t_src.getRequireGradeToExecute())
{
	if ((t_src.getRequireGradeToSigne() < m_maxGrade) || (t_src.getRequireGradeToExecute() < m_maxGrade))
		throw AForm::GradeTooHighException();
	else if ((t_src.getRequireGradeToSigne() > m_minGrade) || (t_src.getRequireGradeToExecute() > m_minGrade))
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string t_name, int t_gradeToSigned, int t_gradeToExecute) :
	m_name(t_name),
	m_isSigned(false),
	m_requireGradeToSigne(t_gradeToSigned),
	m_requireGradeToExecute(t_gradeToExecute)
{
	if ((t_gradeToSigned < m_maxGrade) || (t_gradeToExecute < m_maxGrade))
		throw AForm::GradeTooHighException();
	else if ((t_gradeToSigned > m_minGrade) || (t_gradeToExecute > m_minGrade))
		throw AForm::GradeTooLowException();
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
		throw Bureaucrat::GradeTooLowException();
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
		throw Bureaucrat::GradeTooLowException();
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
	return "Form's grade is too low";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Form's grade is too high";
}

const char	*AForm::FormIsNotSigned::what() const throw()
{
	return "Error: Form is not signed";
}
