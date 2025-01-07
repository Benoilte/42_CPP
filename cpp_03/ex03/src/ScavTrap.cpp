#include "ScavTrap.hpp"

const int ScavTrap::hitAmount = 100;
const int ScavTrap::energyAmount = 50;
const int ScavTrap::attackDamageAmount = 20;

ScavTrap::ScavTrap()
{
   std::cout << "ScavTrap Default constructor is called: " << _name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor is called: " << _name << " is copied" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, hitAmount, energyAmount, attackDamageAmount)
{
	std::cout << "ScavTrap Parametrized constructor is called: " << _name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor is called: " << _name << " is destroy" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);

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
