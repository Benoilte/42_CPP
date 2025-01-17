#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:

		AAnimal();
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();

		AAnimal	&operator=(const AAnimal &rhs);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
		virtual void	displayIdeas() const = 0;
		virtual void	setIdea(unsigned int t_pos, std::string t_idea) = 0;
		virtual Brain	*getBrainPtr(void) = 0;

	protected:

		AAnimal(const std::string &type);

		std::string	m_type;

	private:

};

#endif
