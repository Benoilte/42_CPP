#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include <iostream>
class AMateria;

class ICharacter
{
	public:

		ICharacter();
		// ICharacter(int const t_n);
		ICharacter(const ICharacter &t_src);
		virtual ~ICharacter();

		virtual std::string const	&getName() const = 0;
		virtual void				equip(AMateria* t_materia) = 0;
		virtual void				unequip(int t_idx) = 0;
		virtual void				use(int t_idx, ICharacter& t_target) = 0;

		// ICharacter	&operator=(const ICharacter &t_rhs);

};

#endif
