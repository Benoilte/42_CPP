#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:

		std::string	m_name;
		AMateria	*m_inventory[4];

	public:

		Character();
		Character(std::string const t_name);
		Character(const Character &t_src);
		~Character();

		Character	&operator=(const Character &t_rhs);

		virtual std::string const	&getName() const;
		virtual void 				equip(AMateria* m);
		virtual void 				unequip(int idx);
		virtual void 				use(int idx, ICharacter& target);
};

#endif
