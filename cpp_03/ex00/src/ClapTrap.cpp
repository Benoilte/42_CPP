#include "ClapTrap.hpp"

const int ClapTrap::hitAmount = 10;
const int ClapTrap::energyAmount = 10;
const int ClapTrap::attackDamageAmount = 0;

ClapTrap::ClapTrap()
: _name("anonymous"), _hitPoints(hitAmount), _energyPoints(energyAmount), _attackDamage(attackDamageAmount)
{
    std::cout << "ClapTrap Default constructor is called: " << _name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
: _name(src.getName()), _hitPoints(src.getHitPoints()), _energyPoints(src.getEnergyPoints()), _attackDamage(src.getAttackDamage())
{
	std::cout << "ClapTrap Copy constructor is called: " << _name << " is copied" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
: _name(name), _hitPoints(hitAmount), _energyPoints(energyAmount), _attackDamage(attackDamageAmount)
{
	std::cout << "ClapTrap Parametrized constructor is called: " << _name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor is called: " << _name << " is destroy" << std::endl;
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
	if (ActionCanBePerfomed("attacks someone"))
	{
		std::cout << MAGENTA << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << CYAN << "ClapTrap " << _name << " lose " << amount << " points of hit!" << RESET << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (ActionCanBePerfomed("repair itself"))
	{
		std::cout << GREEN << "ClapTrap " << _name << " repaired itself by " << amount << " points of hit!" << RESET << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}	
}

bool ClapTrap::ActionCanBePerfomed(std::string const &action)
{
	if (_energyPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << _name << " cannot " << action <<", it has no energy points left" << RESET << std::endl;
		return false;
	}
	if (_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << _name << " cannot " << action <<", it has no hit points left" << RESET << std::endl;
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream &out, ClapTrap const &rhs)
{
	out << YELLOW << rhs.getName() << ":\tHit points: " << rhs.getHitPoints() << "\tEnergy points: " << rhs.getEnergyPoints() << RESET;
	return out;
}
