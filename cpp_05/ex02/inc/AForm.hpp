#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <stdexcept>

class	Bureaucrat;

# include "Bureaucrat.hpp"
# include "colors.hpp"

class AForm
{
	private:
	
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

	protected:

		// PROTECTED CONSTRUCTOR //

		AForm(const std::string t_name, int t_gradeToSigned, int t_gradeToExecute);

	public:

		// CONSTRUCTOR //

		AForm();
		AForm(const AForm &t_src);

		// DESTRUCTOR //

		virtual ~AForm();

		// OPERATOR OVERLOAD //

		AForm	&operator=(const AForm &t_rhs);

		// GETTER //

		const std::string	getName(void) const;
		int					getIsSigned(void) const;
		int					getRequireGradeToSigne(void) const;
		int					getRequireGradeToExecute(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		virtual void		beSigned(Bureaucrat &t_signer) = 0;
		virtual void		beExectuted(Bureaucrat &t_executer) = 0;

};

std::ostream	&operator<<(std::ostream &t_out, AForm const &t_rhs);

#endif
