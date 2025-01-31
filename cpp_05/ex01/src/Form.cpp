#include "Form.hpp"

Form::Form() :
	m_name("default"),
	m_isSigned(false),
	m_requireGradeToSigne(42),
	m_requireGradeToExecute(42)
{
    /*Constructor*/
}

Form::Form(const Form &t_src) :
	m_name(t_src.getName()),
	m_isSigned(t_src.getIsSigned()),
	m_requireGradeToSigne(t_src.getRequireGradeToSigne()),
	m_requireGradeToExecute(t_src.getRequireGradeToExecute())
{
	if ((t_src.getRequireGradeToSigne() < 1) || (t_src.getRequireGradeToExecute() < 1))
		throw Form::GradeTooHighException();
	else if ((t_src.getRequireGradeToSigne() > 150) || (t_src.getRequireGradeToExecute() > 150))
		throw Form::GradeTooLowException();
}

Form::Form(const std::string t_name, int t_gradeToSigned, int t_gradeToExecute) :
	m_name(t_name),
	m_isSigned(false),
	m_requireGradeToSigne(t_gradeToSigned),
	m_requireGradeToExecute(t_gradeToExecute)
{
	if ((t_gradeToSigned < 1) || (t_gradeToExecute < 1))
		throw Form::GradeTooHighException();
	else if ((t_gradeToSigned > 150) || (t_gradeToExecute > 150))
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	/*Destructor*/
}

Form& Form::operator=(const Form &t_rhs)
{
	if (this != &t_rhs)
		this->m_isSigned = t_rhs.getIsSigned();

	return *this;
}

const std::string Form::getName(void) const { return m_name; }

int Form::getIsSigned(void) const { return m_isSigned; }

int Form::getRequireGradeToSigne(void) const { return m_requireGradeToSigne; }

int Form::getRequireGradeToExecute(void) const { return m_requireGradeToExecute; }

void Form::beSigned(Bureaucrat &t_signer)
{
	if (t_signer.getGrade() <= getRequireGradeToSigne()) {
		m_isSigned = true;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Form::beExectuted(Bureaucrat &t_executer)
{
	if (t_executer.getGrade() <= getRequireGradeToExecute()) {
		m_isSigned = true;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &t_out, Form const &t_rhs)
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

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Form's grade is too low";
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Form's grade is too high";
}
