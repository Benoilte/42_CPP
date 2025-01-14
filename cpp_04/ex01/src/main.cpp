#include "utils.hpp"

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./checkYourAnimals 0': test Copy constructor and overload assignement" << std::endl;
	std::cout << "'./checkYourAnimals 1': test example from previous exercise" << std::endl;
	std::cout << "'./checkYourAnimals 2': test an Array of animals" << std::endl;
}

void test0(void)
{
	// construct animal, dog1 and cat1
	Animal	animal;
	Dog		dog1;
	Cat		cat1;

	// display their type
	std::cout << std::endl;
	std::cout << animal.getType() << " " << std::endl;
	std::cout << dog1.getType() << " " << std::endl;
	std::cout << cat1.getType() << " " << std::endl;
	std::cout << std::endl;

	// set dog1 ideas
	dog1.setIdea(0, "I'm hungry!");
	dog1.setIdea(1, "I want to eat a cat!");

	// display dog1 ideas
	std::cout << "dog1's ideas: " << std::endl;
	dog1.displayIdeas();
	std::cout << std::endl;

	// set cat1 ideas
	cat1.setIdea(0, "Please let me sleep");
	cat1.setIdea(1, "Oh noooo i don't like this dog!");

	// display cat1 ideas
	std::cout << "cat1's ideas: " << std::endl;
	cat1.displayIdeas();
	std::cout << std::endl;

	std::cout << MAGENTA << "copy dog1 into dog2 and cat1 into cat2 with copy constructor" << RESET << std::endl;
	Dog		dog2(dog1);
	Cat		cat2(cat1);

	// display dog2 ideas
	std::cout << "\ndog2's ideas: " << std::endl;
	dog2.displayIdeas();
	std::cout << std::endl;

	// display cat2 ideas
	std::cout << "cat2's ideas: " << std::endl;
	cat2.displayIdeas();
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << animal.getType() << "\t" << "Brain existence: " << animal.getBrainPtr() << "\t\t";
	animal.makeSound();	// will output the animal song!
	std::cout << dog1.getType() << "\t" << "Brain existence: " << dog1.getBrainPtr() << "\t";
	dog1.makeSound();	//will output the dog sound!
	std::cout << cat1.getType() << "\t" << "Brain existence: " << cat1.getBrainPtr() << "\t";
	cat1.makeSound();	//will output the cat sound!
	std::cout << dog2.getType() << "\t" << "Brain existence: " << dog2.getBrainPtr() << "\t";
	dog2.makeSound();	//will output the dog sound!
	std::cout << cat2.getType() << "\t" << "Brain existence: " << cat2.getBrainPtr() << "\t";
	cat2.makeSound();	//will output the cat sound!
	std::cout << std::endl;

	std::cout << MAGENTA << "Create cat3 and copy cat1 into cat3 with overload operator assignement" << RESET << std::endl;
	Cat		cat3;
	cat3 = cat1;

	// display cat1 ideas
	std::cout << std::endl;
	std::cout << "cat1's ideas: " << std::endl;
	cat1.displayIdeas();
	std::cout << std::endl;

	// display cat3 ideas
	std::cout << "cat3's ideas: " << std::endl;
	cat3.displayIdeas();
	std::cout << std::endl;

	std::cout << cat1.getType() << "\t" << "Brain existence: " << cat1.getBrainPtr() << "\t";
	cat1.makeSound();	//will output the cat sound!
	std::cout << cat3.getType() << "\t" << "Brain existence: " << cat3.getBrainPtr() << "\t";
	cat3.makeSound();	//will output the cat sound!
	std::cout << std::endl;
}

void test1(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << meta->getType() << "\t";
	meta->makeSound();	//will output the animal sound!
	std::cout << dog->getType() << "\t";
	dog->makeSound();	//will output the dog sound!
	std::cout << cat->getType() << "\t";
	cat->makeSound();	//will output the cat sound!
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
}

void test2(void)
{
	Animal	*animals[6];
	Animal	*cat = new Cat();
	Animal	*dog = new Dog();
	std::cout << std::endl;

	// set dog ideas
	dog->setIdea(0, "I'm hungry!");
	dog->setIdea(1, "I want to eat a cat!");
	dog->setIdea(2, "Is time to eat, right ?");
	dog->setIdea(3, "I want to eat an army of cat!");

	// set cat ideas
	cat->setIdea(0, "Please let me sleep");
	cat->setIdea(1, "Oh noooo I don't like this dog!");
	cat->setIdea(2, "I'm going to sleep on the couch!");
	cat->setIdea(3, "Oh its looks suny outside, I'm going to sleep under the sun!");

	// set a new cat or dog with a coopy constructor
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat(*((Cat *)cat));
		else
			animals[i] = new Dog(*((Dog *)dog));
	}

	// update third idea of cat in position 2
	animals[2]->setIdea(3, "Its raining outside.. Couch is soooo confortable to sleep!");
	// add a fourth idea of dog in position 3
	animals[3]->setIdea(4, "I will die of starvation!");

	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << MAGENTA << i << ": " << animals[i]->getType() << " Brain existence: " << animals[i]->getBrainPtr() << RESET << std::endl;
		animals[i]->displayIdeas();
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	// copy dog in position 3 into dog in position 1;
	std::cout << YELLOW << "copy dog in position 3 into dog in position 1: " << RESET << std::endl;
	*animals[1] = *animals[3];
	std::cout << MAGENTA << 1 << ": "  << animals[1]->getType() << " Brain existence: " << animals[1]->getBrainPtr() << RESET << std::endl;
	animals[1]->displayIdeas();
	animals[1]->makeSound();
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		delete animals[i];
	}
	std::cout << std::endl;
	delete cat;
	delete dog;
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

			default:
				help();
				break;
		}
	}
	else
		help();
	return (0);
}
