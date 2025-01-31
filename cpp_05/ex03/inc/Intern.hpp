#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	
		

		// PRIVATE ATTRIBUTE //

		// PRIVATE MEMBER FUNCTION //
		AForm	*makePresidentialPardon(std::string t_target);
		AForm	*makeRobotomyRequest(std::string t_target);
		AForm	*makeShrubberyCreation(std::string t_target);

		// EXCEPTION //

		class FormNotExist : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	public:

		// CONSTRUCTOR //

		Intern();
		Intern(const Intern &t_src);

		// DESTRUCTOR //

		~Intern();

		// OPERATOR OVERLOAD //

		Intern	&operator=(const Intern &t_rhs);

		// GETTER //

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		AForm	*makeForm(std::string t_formName, std::string t_target);

};

#endif
