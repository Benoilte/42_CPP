#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <stdexcept>

class	Bureaucrat;

# include "Bureaucrat.hpp"
# include "colors.hpp"

class Form
{
	private:
		
		// STATIC PRIVATE ATTRIBUTE //

		const static int	m_minGrade = 150; 
		const static int	m_maxGrade = 1;
		const static int	m_defaultGrade = 42;

		// PRIVATE ATTRIBUTE //

		const std::string	m_name;
		bool				m_isSigned;
		const int			m_requireGradeToSigne;
		const int			m_requireGradeToExecute;

		// PRIVATE MEMBER FUNCTION //

		// EXCEPTION //

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	public:

		// CONSTRUCTOR //

		Form();
		Form(const std::string t_name, int t_gradeToSigned, int t_gradeToExecute);
		Form(const Form &t_src);

		// DESTRUCTOR //

		~Form();

		// OPERATOR OVERLOAD //

		Form	&operator=(const Form &t_rhs);

		// GETTER //

		const std::string	getName(void) const;
		int					getIsSigned(void) const;
		int					getRequireGradeToSigne(void) const;
		int					getRequireGradeToExecute(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		void				beSigned(Bureaucrat &t_signer);
		void				beExectuted(Bureaucrat &t_executer);

};

std::ostream	&operator<<(std::ostream &t_out, Form const &t_rhs);

#endif
