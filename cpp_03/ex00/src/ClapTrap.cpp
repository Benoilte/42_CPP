#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
: _name("anonymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor is called" << std::endl;
	std::cout << *this << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;

	return ;
}

ClapTrap::ClapTrap(const std::string name) 
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parametrized constructor is called" << std::endl;
	std::cout << *this << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is called: ClapTrap " << _name << " is destroy" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
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

std::string ClapTrap::getName(void) const
{
	return _name;
}

int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << 1 << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " lose " << amount << " points of hit!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " repaired itself by " << amount << " points of hit!" << std::endl;
}

std::ostream& operator<<(std::ostream &out, ClapTrap const &rhs)
{
	out << "ClapTrap " << rhs.getName() << " Hit points: " << rhs.getHitPoints() << " Energy points: " << rhs.getEnergyPoints() << " Attack damage: " << rhs.getAttackDamage();
	return out; 
}