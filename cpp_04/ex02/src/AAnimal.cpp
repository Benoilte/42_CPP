#include "AAnimal.hpp"

AAnimal::AAnimal()
: 	m_type("AAnimal"),
	m_brain(NULL)
{
	std::cout << "AAnimal default constructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &t_src)
: 	m_type("AAnimal"),
	m_brain(NULL)
{
	std::cout << "AAnimal copy constructor is called" << std::endl;
	*this = t_src;
	return ;
}

AAnimal::AAnimal(const std::string &t_type)
:	m_type(t_type),
	m_brain(NULL)
{
	std::cout << "AAnimal protected constructor is called" << std::endl;
}

void AAnimal::displayIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!m_brain->getIdeas(i).empty())
			std::cout << i << ": " << m_brain->getIdeas(i) << std::endl;
	}
}

void AAnimal::setIdea(unsigned int t_pos, std::string t_idea)
{
	m_brain->setIdeas(t_pos, t_idea);
}

Brain* AAnimal::getBrainPtr(void)
{
	return m_brain;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor is called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &t_rhs)
{
	if (this != &t_rhs)
	{
		this->m_type = t_rhs.m_type;
		if (m_brain)
			*m_brain = *t_rhs.m_brain;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return m_type;
}
