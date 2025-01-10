#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << YELLOW << "Cat default constructor is called" << RESET << std::endl;
}

Cat::Cat(const Cat &t_src) : Animal(t_src)
{
	std::cout << YELLOW << "Cat copy constructor is called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat destructor is called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &t_rhs)
{
	if (this != &t_rhs)
		Animal::operator=(t_rhs);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouw" << std::endl;
}
