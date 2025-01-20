#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
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

		RobotomyRequestForm();
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

};

// std::ostream	&operator<<(std::ostream &t_out, RobotomyRequestForm const &t_rhs);

#endif
