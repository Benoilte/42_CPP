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
	if (m_brain != NULL)
		delete m_brain;
	std::cout << CYAN << "Dog destructor is called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &t_rhs)
{
	if (this != &t_rhs)
	{
		Animal::operator=(t_rhs);
		*m_brain = *t_rhs.m_brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wouaff" << std::endl;
}

void Dog::displayIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!m_brain->getIdeas(i).empty())
			std::cout << i << ": " << m_brain->getIdeas(i) << std::endl;
	}
}

void Dog::setIdea(unsigned int t_pos, std::string t_idea)
{
	m_brain->setIdeas(t_pos, t_idea);
}

Brain* Dog::getBrainPtr(void)
{
	return m_brain;
}
