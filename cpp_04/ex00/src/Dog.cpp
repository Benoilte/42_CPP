#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor is called" << std::endl;
}

Dog::Dog(const Dog &src)  : Animal(src)
{
	std::cout << "Dog copy constructor is called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;

}

void Dog::makeSound() const
{
	std::cout << "Wouaff" << std::endl;
}
