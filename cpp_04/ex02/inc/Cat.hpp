#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
#include "AAnimal.hpp"
#include "colors.hpp"

class Cat : public AAnimal
{
	public:

		Cat();
		Cat(const Cat &src);
		~Cat();

		Cat	&operator=(const Cat &rhs);

		void	makeSound() const;

	private:

};

#endif
