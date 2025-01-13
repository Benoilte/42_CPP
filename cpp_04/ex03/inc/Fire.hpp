#ifndef FIRE_HPP
#define FIRE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Fire : public AMateria
{
	public:

		Fire();
		Fire(const Fire &t_src);
		~Fire();

		Fire	&operator=(const Fire &t_rhs);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
