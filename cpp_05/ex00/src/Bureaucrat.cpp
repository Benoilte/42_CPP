#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
: 	m_name("Anonymous"), 
	m_grade(150)
{
    /*Constructor*/
}

Bureaucrat::Bureaucrat(const Bureaucrat &t_src) 
:	m_name(t_src.m_name)
{
	*this = t_src;

	return ;
}

Bureaucrat::Bureaucrat(const std::string t_name, int t_grade) 
: 	m_name(t_name),
	m_grade(150)
{
	if (t_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (t_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		m_grade = t_grade;
}

Bureaucrat::~Bureaucrat()
{
	/*Destructor*/
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &t_rhs)
{
	if (this != &t_rhs)
		this->m_grade = t_rhs.getGrade();
	
	return *this;
}

std::string Bureaucrat::getName(void) const { return m_name; }

int Bureaucrat::getGrade(void) const { return m_grade; }

void Bureaucrat::incrementGrade() { m_grade--; }

void Bureaucrat::decrementGrade() { m_grade++; }

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cout << this->what() << std::endl;
	return "Grade reach too high value";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade reach too low value";
}

std::ostream& operator<<(std::ostream &t_out, Bureaucrat const &t_rhs)
{
	t_out << t_rhs.getName() << ", bureaucrat grade " << t_rhs.getGrade();
	return t_out; 
}