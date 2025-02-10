#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <time.h>
# include <stdlib.h>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

		// PRIVATE STATIC ATTRIBUTE //

		const static int	m_signatureGrade = 72;
		const static int	m_executionGrade = 45;

		// PRIVATE ATTRIBUTE //

		const std::string	m_target;

		// PRIVATE MEMBER FUNCTION //

		// PRIVATE CONSTRUCTOR //
		RobotomyRequestForm();

	public:

		// CONSTRUCTOR //

		RobotomyRequestForm(const std::string t_target);
		RobotomyRequestForm(const RobotomyRequestForm &t_src);

		// DESTRUCTOR //

		~RobotomyRequestForm();

		// OPERATOR OVERLOAD //

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &t_rhs);

		// GETTER //

		const std::string	getTarget(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		virtual void		execute(Bureaucrat &t_executer) const;

};

// std::ostream	&operator<<(std::ostream &t_out, RobotomyRequestForm const &t_rhs);

#endif
