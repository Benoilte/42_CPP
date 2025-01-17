#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include <iostream>
class AMateria;

class ICharacter
{
	public:

		virtual ~ICharacter() {};

		virtual std::string const	&getName() const = 0;
		virtual void				equip(AMateria* t_materia) = 0;
		virtual void				unequip(int t_idx) = 0;
		virtual void				use(int t_idx, ICharacter& t_target) = 0;

};

#endif
