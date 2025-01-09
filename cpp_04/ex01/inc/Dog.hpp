#ifndef DOG_HPP
#define DOG_HPP

# include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:

		Dog();
		Dog(const Dog &src);
		~Dog();

		Dog	&operator=(const Dog &rhs);

		void	makeSound() const;
		void	displayIdeas() const;
		void	setIdea(unsigned int t_pos, std::string t_idea);


	private:
		Brain	*m_brain;
};

#endif
