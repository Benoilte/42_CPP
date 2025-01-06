#include "utils.hpp"

void	help()
{
	std::cout << "Add argument '1' to test ClapTrap class" << std::endl;
}

void	displayStatus(ClapTrap &self)
{
	std::cout << self.getName() << "'s status:\t\t" << self << std::endl;
}

void	test1(void)
{
	// Constructor parametrized
	ClapTrap john("john");

	// Default constructor
	ClapTrap anonymous;

	// Display status after object's creation
	std::cout << std::endl;
	displayStatus(john);
	displayStatus(anonymous);
	std::cout << std::endl;

	// john attack anonymous and display status
	john.attack("anonymous");
	anonymous.takeDamage(john.getAttackDamage());
	displayStatus(john);
	displayStatus(anonymous);
	std::cout << std::endl;

	// joh repairs itself by one and display its status
	john.beRepaired(1);
	displayStatus(john);
	std::cout << std::endl;

	// john attack anonymous until exhaustion
	while (john.getEnergyPoints() > 0)
	{
		john.attack("anonymous");
		anonymous.takeDamage(john.getAttackDamage());
	}
	std::cout << std::endl;
	displayStatus(john);
	displayStatus(anonymous);

	// john try to attack anonymous despite of exhaustion
	john.attack("anonymous");
	// john try to repair himself despite of exhaustion
	john.beRepaired(1);
	std::cout << std::endl;

	// anonymous mutilates himself until no hit points left
	while (anonymous.getHitPoints() > 0)
		anonymous.takeDamage(1);
	displayStatus(anonymous);

	// anonymous try to mutilates himself despite of no hit points left
	anonymous.attack("anonymous");
	// anonymous try to repair himself despite of no hit points left
	anonymous.beRepaired(1);

	std::cout << std::endl;

}

int	main(int argc, char **argv)
{
	if ((argc == 2) && ((std::string)argv[1]).size() == 1)
	{
		switch (argv[1][0])
		{
			case '1':
				std::cout << "test 1:" << std::endl;
				test1();
				break;
			
			default:
				help();
				break;
		}
	}
	else
		help();
	return (0);
}
