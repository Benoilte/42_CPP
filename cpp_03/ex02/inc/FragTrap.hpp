#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &rhs);

		void highFivesGuys(void);

	private:

		static const int hitAmount;
		static const int energyAmount;
		static const int attackDamageAmount;
};

#endif
