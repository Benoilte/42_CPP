#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./checkYourAnimals 0': test Copy constructor and overload assignement" << std::endl;
	std::cout << "'./checkYourAnimals 1': test given from subject" << std::endl;
	std::cout << "'./checkYourAnimals 2': test WrongAnimal and Wrong cat" << std::endl;
	// std::cout << "'./checkYourAnimals 3': test FragTrap class" << std::endl;
	// std::cout << "'./checkYourAnimals 4': test DiamondTrap class" << std::endl;
}

void test0(void)
{
	Animal	animal;
	Dog		dog1;
	Dog		dog2(dog1);
	Cat		cat1;
	Cat		cat2(cat1);

	std::cout << std::endl;
	std::cout << animal.getType() << " " << std::endl;
	std::cout << dog1.getType() << " " << std::endl;
	std::cout << dog2.getType() << " " << std::endl;
	std::cout << cat1.getType() << " " << std::endl;
	std::cout << cat2.getType() << " " << std::endl;
	std::cout << std::endl;
	animal.makeSound();
	dog1.makeSound();
	dog2.makeSound();
	cat1.makeSound();
	cat2.makeSound();
	std::cout << std::endl;
}

void test1(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
}

void test2(void)
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //will output the animal sound!
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
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

			// case '3':
			// 	std::cout << "test 3:" << std::endl;
			// 	test3();
			// 	break;

			// case '4':
			// 	std::cout << "test 4:" << std::endl;
			// 	test4();
			// 	break;

			default:
				help();
				break;
		}
	}
	else
		help();
	return (0);
}
