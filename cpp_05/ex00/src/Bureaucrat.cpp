#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: 	m_name("Anonymous"),
	m_grade(m_minGrade)
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
	m_grade(m_minGrade)
{
	if (t_grade < m_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (t_grade > m_minGrade)
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

void Bureaucrat::incrementGrade()
{
	m_grade--; 
	if (m_grade < m_maxGrade)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	m_grade++;
	if (m_grade > m_minGrade)
		throw Bureaucrat::GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low";
}

std::ostream& operator<<(std::ostream &t_out, Bureaucrat const &t_rhs)
{
	t_out << t_rhs.getName() << ", bureaucrat grade " << t_rhs.getGrade();
	return t_out;
}
