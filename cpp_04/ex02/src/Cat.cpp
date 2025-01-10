#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << YELLOW << "Cat default constructor is called" << RESET << std::endl;
	m_brain = new Brain();
}

Cat::Cat(const Cat &t_src) : AAnimal(t_src)
{
	std::cout << YELLOW << "Cat copy constructor is called" << RESET << std::endl;
	m_brain = new Brain(*t_src.m_brain);
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << YELLOW << "Cat destructor is called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &t_rhs)
{
	if (this != &t_rhs)
		AAnimal::operator=(t_rhs);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouw" << std::endl;
}
