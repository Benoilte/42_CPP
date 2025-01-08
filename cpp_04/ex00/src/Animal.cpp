#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = src;
	return ;
}

Animal::Animal(const std::string &animalType) : type(animalType)
{
	std::cout << "Animal protected constructor is called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Grrrrrr" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
