#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>


class Bureaucrat
{
	private:
	
		// STATIC PRIVATE ATTRIBUTE //

		const static int	m_minGrade = 150; 
		const static int	m_maxGrade = 1; 

		// PRIVATE ATTRIBUTE //

		const std::string	m_name;
		int					m_grade;

		// PRIVATE MEMBER FUNCTION //

	public:

		// CONSTRUCTOR //

		Bureaucrat();
		Bureaucrat(const std::string t_name, int t_grade);
		Bureaucrat(const Bureaucrat &t_src);

		// DESTRUCTOR //

		~Bureaucrat();

		// EXCEPTION //

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// OPERATOR OVERLOAD //

		Bureaucrat	&operator=(const Bureaucrat &t_rhs);

		// GETTER //

		std::string	getName(void) const;
		int			getGrade(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		void		incrementGrade();
		void		decrementGrade();

};

std::ostream	&operator<<(std::ostream &t_out, Bureaucrat const &t_rhs);

#endif
