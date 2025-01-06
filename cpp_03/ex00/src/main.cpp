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

	while (john.getEnergyPoints() > 0)
	{
		john.attack("anonymous");
		anonymous.takeDamage(john.getAttackDamage());
	}
	std::cout << "\ndisplay john's status:\t\t" << john << std::endl;
	std::cout << "display anonymous's status:\t" << anonymous << std::endl;
	std::cout << std::endl;
	john.attack("anonymous");
	john.beRepaired(1);
	std::cout << std::endl;

	while (anonymous.getHitPoints() > 0)
		anonymous.takeDamage(1);
	std::cout << "display anonymous's status:\t" << anonymous << std::endl;
	std::cout << std::endl;
	anonymous.attack("anonymous");
	anonymous.beRepaired(1);

	std::cout << std::endl;

}

int	main(void)
{
	std::cout << "test 1:" << std::endl;
	test1();
	return (0);
}
