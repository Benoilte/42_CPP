#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		
		// PRIVATE STATIC ATTRIBUTE //

		static int	m_signatureGrade;
		static int	m_executionGrade;

		// PRIVATE ATTRIBUTE //

		const std::string	m_target;

		// PRIVATE MEMBER FUNCTION //

	public:

		// CONSTRUCTOR //

		PresidentialPardonForm();
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

		virtual void		beSigned(Bureaucrat &t_signer);
		virtual void		beExectuted(Bureaucrat &t_executer);

};

// std::ostream	&operator<<(std::ostream &t_out, PresidentialPardonForm const &t_rhs);

#endif
