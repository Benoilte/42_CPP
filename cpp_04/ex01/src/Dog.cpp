#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "Dog default constructor is called" << RESET << std::endl;
	m_brain = new Brain();
}

Dog::Dog(const Dog &t_src)  : Animal(t_src)
{
	std::cout << CYAN << "Dog copy constructor is called" << RESET << std::endl;
	m_brain = new Brain(*t_src.m_brain);
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog destructor is called" << RESET << std::endl;
	delete m_brain;
}

Dog& Dog::operator=(const Dog &t_rhs)
{
	std::cout << RED << "Dog operator assignement is called" << RESET << std::endl;
	if (this != &t_rhs)
	{
		Animal::operator=(t_rhs);
		delete m_brain;
		m_brain = new Brain();
		*m_brain = *t_rhs.m_brain;
	}
	return *this;

}

void Dog::makeSound() const
{
	std::cout << "Wouaff" << std::endl;
}
