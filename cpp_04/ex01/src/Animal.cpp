#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal &t_src)
{
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = t_src;
	return ;
}

Animal::Animal(const std::string &t_type) : m_type(t_type)
{
	std::cout << "Animal protected constructor is called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal &t_rhs)
{
	if (this != &t_rhs)
		this->m_type = t_rhs.m_type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Grrrrrr" << std::endl;
}

std::string Animal::getType() const
{
	return m_type;
}
