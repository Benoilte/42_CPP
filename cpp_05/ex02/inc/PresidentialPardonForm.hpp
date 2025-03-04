#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		// PRIVATE STATIC ATTRIBUTE //

		const static int	m_signatureGrade = 25;
		const static int	m_executionGrade = 5;

		// PRIVATE ATTRIBUTE //

		const std::string	m_target;

		// PRIVATE MEMBER FUNCTION //

		// PRIVATE CONSTRUCTOR //
		PresidentialPardonForm();

	public:

		// CONSTRUCTOR //

		PresidentialPardonForm(const std::string t_target);
		PresidentialPardonForm(const PresidentialPardonForm &t_src);

		// DESTRUCTOR //

		~PresidentialPardonForm();

		// OPERATOR OVERLOAD //

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &t_rhs);

		// GETTER //

		const std::string	getTarget(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		virtual void		execute(Bureaucrat &t_executer) const;

};

// std::ostream	&operator<<(std::ostream &t_out, PresidentialPardonForm const &t_rhs);

#endif
