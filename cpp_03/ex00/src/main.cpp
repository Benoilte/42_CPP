#include "ClapTrap.hpp"
#include <iostream>

void	test1(void)
{
	ClapTrap john("john");
	ClapTrap anonymous;

	std::cout << "\ndisplay john's status:\t\t" << john << std::endl;
	std::cout << "display anonymous's status:\t" << anonymous << std::endl;
	std::cout << std::endl;

	john.attack("anonymous");
	anonymous.takeDamage(john.getAttackDamage());
	std::cout << "\ndisplay john's status:\t\t" << john << std::endl;
	std::cout << "display anonymous's status:\t" << anonymous << std::endl;
	std::cout << std::endl;

	john.beRepaired(1);
	std::cout << "\ndisplay john's status:\t\t" << john << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "test 1:" << std::endl;
	test1();
	return (0);
}

