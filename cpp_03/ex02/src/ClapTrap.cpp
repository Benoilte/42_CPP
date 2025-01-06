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
		_hitPoints++;
		_energyPoints--;
	}	
}

ClapTrap::ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage)
: _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "Protected Clap Trap Parametrized constructor is called" << std::endl;
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
