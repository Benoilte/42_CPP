#include "Animal.hpp"

Animal::Animal()
: 	m_type("Animal"),
	m_brain(NULL)
{
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal &t_src)
: 	m_type("Animal"),
	m_brain(NULL)
{
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = t_src;
	return ;
}

Animal::Animal(const std::string &t_type)
:	m_type(t_type),
	m_brain(NULL)
{
	std::cout << "Animal protected constructor is called" << std::endl;
}

void Animal::displayIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!m_brain->getIdeas(i).empty())
			std::cout << i << ": " << m_brain->getIdeas(i) << std::endl;
	}
}

void Animal::setIdea(unsigned int t_pos, std::string t_idea)
{
	m_brain->setIdeas(t_pos, t_idea);
}

Brain* Animal::getBrainPtr(void)
{
	return m_brain;
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal &t_rhs)
{
	if (this != &t_rhs)
	{
		this->m_type = t_rhs.m_type;
		if (m_brain)
			*m_brain = *t_rhs.m_brain;
	}
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