#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>


class Bureaucrat
{
	private:
	
		// PRIVATE ATTRIBUTE //

		const std::string	m_name;
		int					m_grade;

		// PRIVATE MEMBER FUNCTION //

	public:

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

		// CONSTRUCTOR //

		Bureaucrat();
		Bureaucrat(const std::string t_name, int t_grade);
		Bureaucrat(const Bureaucrat &t_src);

		// DESTRUCTOR //

		~Bureaucrat();

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
