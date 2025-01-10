#include "utils.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	std::cout << "ice type: " << &ice << " - " << ice->getType() << std::endl;
	std::cout << "cure type: " << &cure << " - " << cure->getType() << std::endl;

	std::cout << YELLOW << "\nClone Ice and Cure class" << RESET << std::endl;
	AMateria *ice_cloned = ice->clone();
	AMateria *cure_cloned = cure->clone();
	std::cout << "ice_cloned type: " << &ice_cloned << " - " << ice_cloned->getType() << std::endl;
	std::cout << "cure_cloned type: " << &cure_cloned << " - " << cure_cloned->getType() << std::endl;

	delete ice;
	delete cure;
	delete ice_cloned;
	delete cure_cloned;
	return (0);
}

