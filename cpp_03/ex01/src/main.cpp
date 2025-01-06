#include "utils.hpp"

void	help()
{
	std::cout << "Use ./trap 1 to test ClapTrap class" << std::endl;
	std::cout << "Use ./trap 2 to test ScavTrap class" << std::endl;
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

void	test2(void)
{
	ScavTrap marc("Marc");
	ScavTrap joey("Joey");

	// Display status after object's creation
	std::cout << std::endl;
	displayStatus(marc);
	displayStatus(joey);
	std::cout << std::endl;

	// joey attack marc and display status
	joey.attack("marc");
	marc.takeDamage(joey.getAttackDamage());
	displayStatus(joey);
	displayStatus(marc);
	std::cout << std::endl;

	// joey and marc display their gate keeper mode
	joey.guardGate();
	marc.guardGate();
	std::cout << std::endl;

	// marc attack joey until joey has no hit points left
	while (joey.getHitPoints() > 0)
	{
		marc.attack("joey");
		joey.takeDamage(marc.getAttackDamage());
	}
	displayStatus(marc);
	displayStatus(joey);
	std::cout << std::endl;

	// joey try to attack marc despite of no hit points left
	joey.attack("marc");
	// joey try to repair himself despite of no hit points left
	joey.beRepaired(1);
	std::cout << std::endl;


	// marc repair itself until exhaustion
	while (marc.getEnergyPoints() > 0)
		marc.beRepaired(1);
	displayStatus(marc);
	std::cout << std::endl;

	// marc try to attack joey despite of exhaustion
	marc.attack("joey");
	// marc try to repair himself despite of exhaustion
	marc.beRepaired(1);
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

			case '2':
				std::cout << "test 1:" << std::endl;
				test2();
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
