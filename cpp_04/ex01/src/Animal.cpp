#include "Animal.hpp"

Animal::Animal()
: 	m_type("Animal")
{
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal &t_src)
: 	m_type("Animal")
{
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = t_src;
	return ;
}

Animal::Animal(const std::string &t_type)
:	m_type(t_type)
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

std::string Animal::getType() const
{
	return m_type;
}

void Animal::makeSound() const
{
	std::cout << "Grrrrrr" << std::endl;
}

void Animal::displayIdeas() const
{
	std::cout << "I'm just an Animal and I have No Brain !" << std::endl;
}

void Animal::setIdea(unsigned int t_pos, std::string t_idea)
{
	(void)t_pos;
	(void)t_idea;
	std::cout << "I'm just an Animal and I have No Brain !" << std::endl;
}

Brain* Animal::getBrainPtr(void)
{
	return 0;
}
