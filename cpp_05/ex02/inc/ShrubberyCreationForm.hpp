#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

		// PRIVATE STATIC ATTRIBUTE //

		static int	m_signatureGrade;
		static int	m_executionGrade;

		// PRIVATE ATTRIBUTE //

		const std::string	m_target;
		const std::string	m_fileName;

		// PRIVATE MEMBER FUNCTION //

		// PRIVATE CONSTRUCTOR //
		ShrubberyCreationForm();

		// EXCEPTION //

		class FileNotOpen : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	public:

		// CONSTRUCTOR //

		ShrubberyCreationForm(const std::string t_target);
		ShrubberyCreationForm(const ShrubberyCreationForm &t_src);

		// DESTRUCTOR //

		~ShrubberyCreationForm();

		// OPERATOR OVERLOAD //

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &t_rhs);

		// GETTER //

		const std::string	getTarget(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		virtual void		execute(Bureaucrat &t_executer) const;

};

// std::ostream	&operator<<(std::ostream &t_out, ShrubberyCreationForm const &t_rhs);

#endif
