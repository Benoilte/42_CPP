#include "FragTrap.hpp"

const int FragTrap::hitAmount = 100;
const int FragTrap::energyAmount = 100;
const int FragTrap::attackDamageAmount = 30;

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor is called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, hitAmount, energyAmount, attackDamageAmount)
{
	std::cout << "FragTrap Parametrized constructor is called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor is called: " << _name << " is destroy" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap " << _name << ": Give me five bro ;)" << RESET << std::endl;
}