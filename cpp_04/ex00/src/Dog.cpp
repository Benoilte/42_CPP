#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "Dog default constructor is called" << RESET << std::endl;
}

Dog::Dog(const Dog &t_src)  : Animal(t_src)
{
	std::cout << CYAN << "Dog copy constructor is called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog destructor is called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &t_rhs)
{
	if (this != &t_rhs)
		Animal::operator=(t_rhs);
	return *this;

}

void Dog::makeSound() const
{
	std::cout << "Wouaff" << std::endl;
}
