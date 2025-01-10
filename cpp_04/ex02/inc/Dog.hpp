#ifndef DOG_HPP
#define DOG_HPP

# include <iostream>
#include "AAnimal.hpp"
#include "colors.hpp"

class Dog : public AAnimal
{
	public:

		Dog();
		Dog(const Dog &src);
		~Dog();

		Dog	&operator=(const Dog &rhs);

		void	makeSound() const;

	private:

};

#endif
