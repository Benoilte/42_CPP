#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
   std::cout << "Scav Trap Default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "Scav Trap Copy constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Scav Trap Parametrized constructor is called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Trap Destructor is called: " << _name << " is destroy" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}

	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (ActionCanBePerfomed("attacks someone"))
	{
		std::cout << BLUE << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << MAGENTA << "ScavTrap " << _name << " is now in Gatekeeper mode. " << RESET << std::endl;
}
