#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
: _name("anonymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Clap Trap Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;

	return ;
}

ClapTrap::ClapTrap(const std::string name) 
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Clap Trap Parametrized constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Clap Trap Destructor is called: " << _name << " is destroy" << std::endl;
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
	std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " lose " << amount << " points of hit!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself, it has no hit points or energy points left ";
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself, it has no hit points or energy points left ";
	}
	std::cout << "ClapTrap " << _name << " repaired itself by " << amount << " points of hit!" << std::endl;
	_hitPoints++;
	_energyPoints--;
}

std::ostream& operator<<(std::ostream &out, ClapTrap const &rhs)
{
	out << rhs.getName() << ":\tHit points: " << rhs.getHitPoints() << "\tEnergy points: " << rhs.getEnergyPoints();
	return out; 
}