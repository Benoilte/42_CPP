#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor is called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor is called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouw" << std::endl;
}
