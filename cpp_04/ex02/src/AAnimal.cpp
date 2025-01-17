#include "AAnimal.hpp"

AAnimal::AAnimal()
: 	m_type("AAnimal")
{
	std::cout << "AAnimal default constructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &t_src)
: 	m_type("AAnimal")
{
	std::cout << "AAnimal copy constructor is called" << std::endl;
	*this = t_src;
	return ;
}

AAnimal::AAnimal(const std::string &t_type)
:	m_type(t_type)
{
	std::cout << "AAnimal protected constructor is called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor is called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &t_rhs)
{
	if (this != &t_rhs)
		this->m_type = t_rhs.m_type;
	return *this;
}

std::string AAnimal::getType() const
{
	return m_type;
}
