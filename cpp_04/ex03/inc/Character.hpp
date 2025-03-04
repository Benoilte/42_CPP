#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "colors.hpp"

class Character : public ICharacter
{
	private:

		static const int	m_inventorySize;
		static AMateria		**m_unused;
		static unsigned int	m_unusedSize;
		static unsigned int	m_characterCount;

		std::string const	m_name;
		AMateria			*m_inventory[4];

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

		static	void				displayCharacters(const Character &c1);
		static	void				displayCharacters(const Character &c1, const Character &c2);
		static	void				displayUnusedMateria();
};

#endif
