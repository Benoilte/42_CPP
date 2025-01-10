#ifndef ICE_HPP
#define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice(const Ice &t_src);
		~Ice();

		Ice	&operator=(const Ice &t_rhs);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

// std::ostream	&operator<<(std::ostream &t_out, Ice const &t_rhs);

#endif
