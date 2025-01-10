#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
#include "Brain.hpp"

class Animal
{
	public:

		Animal();
		Animal(const Animal &src);
		virtual ~Animal();

		Animal	&operator=(const Animal &rhs);

		std::string		getType() const;
		virtual void	makeSound() const;
		void			displayIdeas() const;
		void			setIdea(unsigned int t_pos, std::string t_idea);
		Brain			*getBrainPtr(void);

	protected:

		Animal(const std::string &type);

		std::string	m_type;
		Brain		*m_brain;

	private:

};

#endif
