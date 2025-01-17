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
		virtual void			displayIdeas() const;
		virtual void			setIdea(unsigned int t_pos, std::string t_idea);
		virtual Brain			*getBrainPtr(void);

	protected:

		Animal(const std::string &type);

		std::string	m_type;

	private:

};

#endif
