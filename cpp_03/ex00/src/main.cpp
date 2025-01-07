#include "utils.hpp"

void	help()
{
	std::cout << "Use ./trap 0 to test Copy constructor and overload assignement" << std::endl;
	std::cout << "Use ./trap 1 to test ClapTrap class" << std::endl;
}

void	displayStatus(ClapTrap &self)
{
	std::cout << self.getName() << "'s status:\t\t" << self << std::endl;
}

void	test0(void)
{
	ClapTrap john("John");

	// Display status after john's creation
	std::cout << std::endl;
	std::cout << "Display status after john's creation:" << std::endl;
	displayStatus(john);
	std::cout << john.getName() << "'s attack damage:\t" << john.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// repair itself and copy john copy 1 with copy constructor
	john.beRepaired(2);
	ClapTrap johnCopy1(john);

	// Display status after johnCopy1's creation and copy
	std::cout << std::endl;
	std::cout << "Display status after johnCopy1's creation and copy:" << std::endl;
	displayStatus(johnCopy1);
	std::cout << johnCopy1.getName() << "'s attack damage:\t" << johnCopy1.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// repair itself and copy john copy 2 with overload assignement
	john.beRepaired(2);
	ClapTrap johnCopy2;
	johnCopy2 = john;

	// Display status after johnCopy2's creation and copy
	std::cout << std::endl;
	std::cout << "Display status after johnCopy2's creation and copy:" << std::endl;
	displayStatus(johnCopy2);
	std::cout << johnCopy2.getName() << "'s attack damage:\t" << johnCopy2.getAttackDamage() << std::endl;
	std::cout << std::endl;

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
			case '0':
				std::cout << "test 0:" << std::endl;
				test0();
				break;

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
