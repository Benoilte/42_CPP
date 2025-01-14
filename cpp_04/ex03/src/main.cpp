#include "utils.hpp"

void	help(void)
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./Interfaces 0': test AMateria class: copy constructor and overlad assignement operator and clone function" << std::endl;
	std::cout << "'./Interfaces 1': test Character class: copy constructor and overlad assignement operator" << std::endl;
	std::cout << "'./Interfaces 2': test MateriaSource class: copy constructor and overlad assignement operator" << std::endl;
	std::cout << "'./Interfaces 3': test given from subject" << std::endl;
	std::cout << "'./Interfaces 4': test different characters capacity" << std::endl;
}

void	test0(void)
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *fire = new Fire();

	std::cout << "ice type:\t" << ice->getType() << " - " << &ice << std::endl;
	std::cout << "cure type:\t" << cure->getType() << " - " << &cure << std::endl;
	std::cout << "cure type:\t" << fire->getType() << " - " << &fire << std::endl;

	std::cout << YELLOW << "\nClone Ice, Cure and Fire class:" << RESET << std::endl;
	AMateria *ice_cloned = ice->clone();
	AMateria *cure_cloned = cure->clone();
	AMateria *fire_cloned = fire->clone();
	std::cout << "ice_cloned type:\t" << ice_cloned->getType() << " - " << &ice_cloned << std::endl;
	std::cout << "cure_cloned type:\t" << cure_cloned->getType() << " - " << &cure_cloned << std::endl;
	std::cout << "fire_cloned type:\t" << fire_cloned->getType() << " - " << &fire_cloned << std::endl;

	std::cout << YELLOW << "\nCopy Ice into Ice_copy with overload assignement:" << RESET << std::endl;
	AMateria *ice_copy = new Ice();
	*(Ice *)ice_copy = *(Ice *)ice;
	std::cout << "ice type:\t" << ice->getType() << " - " << &ice << std::endl;
	std::cout << "ice_copy type:\t" << ice_copy->getType() << " - " << &ice_copy << std::endl;

	std::cout << YELLOW << "\nCopy Cure into Cure_copy with copy constructor:" << RESET << std::endl;
	AMateria *cure_copy = new Cure(*(Cure *)cure);
	std::cout << "cure type:\t" << cure->getType() << " - " << &cure << std::endl;
	std::cout << "cure_copy type:\t" << cure_copy->getType() << " - " << &cure_copy << std::endl;

	delete ice;
	delete cure;
	delete fire;
	delete ice_cloned;
	delete cure_cloned;
	delete fire_cloned;
	delete ice_copy;
	delete cure_copy;
}

void	test1(void)
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

	std::cout << CYAN << "unequip second Materia of bob and copy bob into joe" << RESET << std::endl;
	Character::displayCharacters(*(Character *)bob);
	bob->unequip(2);
	*(Character *)joe = *(Character *)bob;
	Character::displayCharacters(*(Character *)bob, *(Character *)joe);

	delete bob;
	delete bob_copy;
	delete ben;
	delete joe;
	delete joe_copy;
	delete src;
}

void	test2(void)
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

void	test3(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());

	ICharacter* ben = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	ben->equip(tmp);
	tmp = src->createMateria("cure");
	ben->equip(tmp);
	tmp = src->createMateria("fire");
	ben->equip(tmp);


	ICharacter* bob = new Character("bob");

	ben->use(0, *bob);
	ben->use(1, *bob);
	ben->use(2, *bob);

	delete bob;
	delete ben;
	delete src;
}

void	test4(void)
{
	IMateriaSource* src = new MateriaSource();

	std::cout << CYAN << "\nlearn 5 Materia int src MateriaSource the last one (ice) won't be added and directly deleted" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	ICharacter* ben = new Character("me");
	AMateria* tmp;

	std::cout << CYAN << "\nEquip ben with 5 materia. The last one (fire) will be set as unused" << RESET << std::endl;
	tmp = src->createMateria("ice");
	ben->equip(tmp);
	tmp = src->createMateria("cure");
	ben->equip(tmp);
	tmp = src->createMateria("fire");
	ben->equip(tmp);
	tmp = src->createMateria("ice");
	ben->equip(tmp);
	tmp = src->createMateria("fire");
	ben->equip(tmp);
	Character::displayCharacters(*(Character *)ben);

	std::cout << CYAN << "\nCreate bob and use the three first materia of ben with bob as target" << RESET << std::endl;
	ICharacter* bob = new Character("bob");
	ben->use(0, *bob);
	ben->use(1, *bob);
	ben->use(2, *bob);

	std::cout << CYAN << "\nUnequip position 1 (cure materia) of ben and try to use this materia" << RESET << std::endl;
	ben->unequip(1);
	ben->use(1, *bob);
	Character::displayCharacters(*(Character *)ben);

	std::cout << CYAN << "\nEquip ben with an additional fire and us it" << RESET << std::endl;
	tmp = src->createMateria("fire");
	ben->equip(tmp);
	ben->use(1, *bob);
	Character::displayCharacters(*(Character *)ben);

	delete bob;
	delete ben;
	delete src;
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

			case '4':
				std::cout << "test 4:" << std::endl;
				test4();
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

