#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie *john, *marc;

	// Create new allocated zombie John, Annouce it and delete it
	john = newZombie("John");
	if (john == NULL) return (1);
	john->announce();
	delete john;
	
	// Create zombie Michael in the randomChump function scope
	randomChump("Michael");

	// Create zombie Damien in the randomChump function scope
	randomChump("Damien");

	// Create new allocated zombie Marc, Annouce it and delete it
	marc = newZombie("Marc");
	if (marc == NULL) return (2);
	marc->announce();
	delete marc;
	return (0);
}
