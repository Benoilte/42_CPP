#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include "colors.hpp"

class ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &rhs);

		std::string getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	private:

		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		static const int hitAmount;
		static const int energyAmount;
		static const int attackDamageAmount;

		bool		ActionCanBePerfomed(std::string const &action);
};

std::ostream	&operator<<(std::ostream &out, ClapTrap const &rhs);

#endif
