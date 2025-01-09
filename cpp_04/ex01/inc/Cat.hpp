#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat();
		Cat(const Cat &src);
		~Cat();

		Cat	&operator=(const Cat &rhs);

		void	makeSound() const;
		void	displayIdeas() const;
		void	setIdea(unsigned int t_pos, std::string t_idea);

	private:
		Brain	*m_brain;

};

#endif
