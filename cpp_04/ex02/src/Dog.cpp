#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << CYAN << "Dog default constructor is called" << RESET << std::endl;
	m_brain = new Brain();
}

Dog::Dog(const Dog &t_src)  : AAnimal(t_src)
{
	std::cout << CYAN << "Dog copy constructor is called" << RESET << std::endl;
	m_brain = new Brain(*t_src.m_brain);
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << CYAN << "Dog destructor is called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &t_rhs)
{
	if (this != &t_rhs)
		AAnimal::operator=(t_rhs);
	return *this;

}

void Dog::makeSound() const
{
	std::cout << "Wouaff" << std::endl;
}
