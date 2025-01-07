#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);

		void 		attack(const std::string& target);
		void 		guardGate(void);

	protected:
		static const int hitAmount;
		static const int energyAmount;
		static const int attackDamageAmount;
	
};

#endif
