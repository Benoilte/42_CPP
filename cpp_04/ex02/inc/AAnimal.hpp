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
		void			displayIdeas() const;
		void			setIdea(unsigned int t_pos, std::string t_idea);
		Brain			*getBrainPtr(void);

	protected:

		AAnimal(const std::string &type);

		std::string	m_type;
		Brain		*m_brain;

	private:

};

#endif
