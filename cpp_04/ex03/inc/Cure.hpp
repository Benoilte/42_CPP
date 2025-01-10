#ifndef CURE_HPP
#define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:

		Cure();
		Cure(const Cure &t_src);
		~Cure();

		Cure	&operator=(const Cure &t_rhs);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

// std::ostream	&operator<<(std::ostream &t_out, Cure const &t_rhs);

#endif
