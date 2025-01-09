#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./checkYourAnimals 0': test Copy constructor and overload assignement" << std::endl;
	std::cout << "'./checkYourAnimals 1': test given from subdogect" << std::endl;
	std::cout << "'./checkYourAnimals 2': test WrongAnimal and Wrong cat" << std::endl;
	std::cout << "'./checkYourAnimals 3': test pointer type same as class type" << std::endl;
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
	dog1.makeSound();	//will output the dog sound!
	dog2.makeSound();	//will output the dog sound!
	cat1.makeSound();	//will output the cat sound!
	cat2.makeSound();	//will output the cat sound!
	std::cout << std::endl;
}

void test1(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;

	cat->makeSound();	//will output the cat sound!
	dog->makeSound();	//will output the dog sound!
	meta->makeSound();	//will output the animal sound!
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
}

void test2(void)
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << std::endl;

	wrongCat->makeSound();	//will output the animal sound!
	meta->makeSound();		//will output the animal sound!
	std::cout << std::endl;

	delete meta;
	delete wrongCat;
}

void test3(void)
{
	const Dog* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound(); //will output the dog sound!
	std::cout << std::endl;

	delete dog;
	delete cat;
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
