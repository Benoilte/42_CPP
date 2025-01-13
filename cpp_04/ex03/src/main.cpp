#include "utils.hpp"

void	help(void)
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./Interfaces 0': test AMateria class with Ice and Cure implementing clone function" << std::endl;
	std::cout << "'./Interfaces 1': test given from subject" << std::endl;
	std::cout << "'./Interfaces 2': test Character copy constructor and overlad assignement operator" << std::endl;
	std::cout << "'./Interfaces 3': test MateriaSource copy constructor and overlad assignement operator" << std::endl;
}

void	test0(void)
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *fire = new Fire();

	std::cout << "ice type: " << &ice << " - " << ice->getType() << std::endl;
	std::cout << "cure type: " << &cure << " - " << cure->getType() << std::endl;
	std::cout << "cure type: " << &fire << " - " << fire->getType() << std::endl;

	std::cout << YELLOW << "\nClone Ice, Cure and Fire class" << RESET << std::endl;
	AMateria *ice_cloned = ice->clone();
	AMateria *cure_cloned = cure->clone();
	AMateria *fire_cloned = fire->clone();
	std::cout << "ice_cloned type: " << &ice_cloned << " - " << ice_cloned->getType() << std::endl;
	std::cout << "cure_cloned type: " << &cure_cloned << " - " << cure_cloned->getType() << std::endl;
	std::cout << "fire_cloned type: " << &fire_cloned << " - " << fire_cloned->getType() << std::endl;

	delete ice;
	delete cure;
	delete fire;
	delete ice_cloned;
	delete cure_cloned;
	delete fire_cloned;
}

void	test1(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;
}

void	test2(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* ben = new Character("ben");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	ben->equip(tmp);
	tmp = src->createMateria("cure");
	ben->equip(tmp);
	tmp = src->createMateria("ice");
	ben->equip(tmp);
	tmp = src->createMateria("cure");
	ben->equip(tmp);
	tmp = src->createMateria("ice");
	ben->equip(tmp);
	tmp = src->createMateria("cure");
	ben->equip(tmp);


	std::cout << CYAN << "create 'ben' character with 4 materia in this inventory and 2 unused materia\n";
	std::cout << "create 'bob' character with 0 materia in this inventory and 0 unused materia\n";
	std::cout << "copy ben into bob to demonstrate deep copy with assignement overload" << RESET << std::endl;

	ICharacter* bob = new Character("bob");
	Character::displayCharacters(*(Character *)ben, *(Character *)bob);

	*(Character *)bob = *(Character *)ben;
	Character::displayCharacters(*(Character *)ben, *(Character *)bob);

	std::cout << std::endl;

	std::cout << CYAN << "create 'joe' character with 0 materia in this inventory and 0 unused materia\n";
	std::cout << "copy joe into ben to demonstrate deep copy with assignement overload" << RESET << std::endl;
	ICharacter* joe = new Character("joe");
	Character::displayCharacters(*(Character *)ben, *(Character *)joe);

	*(Character *)ben = *(Character *)joe;
	Character::displayCharacters(*(Character *)ben, *(Character *)joe);

	std::cout << std::endl;

	std::cout << CYAN << "create 'bob_copy' character with copy constructor" << RESET << std::endl;
	ICharacter* bob_copy = new Character((*(Character *)bob));
	Character::displayCharacters(*(Character *)bob_copy, *(Character *)bob);

	std::cout << std::endl;

	std::cout << CYAN << "create 'joe_copy' character with copy constructor" << RESET << std::endl;
	ICharacter* joe_copy = new Character((*(Character *)joe));
	Character::displayCharacters(*(Character *)joe_copy, *(Character *)joe);

	std::cout << std::endl;

	std::cout << CYAN << "unequip second Materia of bob and display it" << RESET << std::endl;
	Character::displayCharacters(*(Character *)bob);
	bob->unequip(2);
	Character::displayCharacters(*(Character *)bob);

	delete bob;
	delete bob_copy;
	delete ben;
	delete joe;
	delete joe_copy;
	delete src;
}

void	test3(void)
{
	IMateriaSource* src1 = new MateriaSource();

	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Fire());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	std::cout << std::endl;
	std::cout << CYAN << "create 'src1' MateriaSource with 4 materia in this memory\n";
	std::cout << "create 'src2' MateriaSource with 0 materia in this memory\n";
	std::cout << "copy 'src1' into 'src2' to demonstrate deep copy with assignement overload" << RESET << std::endl;
	
	IMateriaSource* src2 = new MateriaSource();
	*(MateriaSource *)src2 = *(MateriaSource *)src1;
	MateriaSource::displayMateriaSources(*(MateriaSource *)src1, *(MateriaSource *)src2);

	std::cout << std::endl;
	std::cout << CYAN << "create 'src3' MateriaSource with 0 materia in this memory\n";
	std::cout << "copy 'src3' into 'src1' to demonstrate deep copy with assignement overload" << RESET << std::endl;
	
	IMateriaSource* src3 = new MateriaSource();
	*(MateriaSource *)src1 = *(MateriaSource *)src3;
	MateriaSource::displayMateriaSources(*(MateriaSource *)src3, *(MateriaSource *)src1);

	delete src1;
	delete src2;
	delete src3;
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

			case '2':
			 	std::cout << "test 2:" << std::endl;
			 	test2();
			 	break;

			case '3':
				std::cout << "test 3:" << std::endl;
				test3();
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

