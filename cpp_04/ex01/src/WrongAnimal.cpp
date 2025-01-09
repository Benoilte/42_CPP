#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &t_src)
{
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
	*this = t_src;
	return ;
}

WrongAnimal::WrongAnimal(const std::string &t_type) : m_type(t_type)
{
	std::cout << "WrongAnimal protected constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &t_rhs)
{
	if (this != &t_rhs)
		this->m_type = t_rhs.m_type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return m_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Grrrrrr" << std::endl;
}
