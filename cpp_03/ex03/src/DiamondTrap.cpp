#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap Copy constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) 
: ClapTrap(name + "_clap_name", FragTrap::hitAmount, ScavTrap::energyAmount, FragTrap::attackDamageAmount), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Parametrized constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor is called: " << FragTrap::_name << " is destroy" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs)
{
	(void)rhs;
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << YELLOW << "ClapTrap name: " << this->getName() << RESET << std::endl;
	std::cout << YELLOW << "DiamondTrap name: " << _name << RESET << std::endl;
}
