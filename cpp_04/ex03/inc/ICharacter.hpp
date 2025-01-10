#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter
{
	public:

		ICharacter();
		// ICharacter(int const t_n);
		ICharacter(const ICharacter &t_src);
		virtual ~ICharacter();

		virtual std::string const	&getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

		// ICharacter	&operator=(const ICharacter &t_rhs);

};

#endif
