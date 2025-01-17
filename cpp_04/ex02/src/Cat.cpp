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
	if (m_brain != NULL)
		delete m_brain;
	std::cout << YELLOW << "Cat destructor is called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &t_rhs)
{
	if (this != &t_rhs)
	{
		AAnimal::operator=(t_rhs);
		*m_brain = *t_rhs.m_brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouw" << std::endl;
}

void Cat::displayIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!m_brain->getIdeas(i).empty())
			std::cout << i << ": " << m_brain->getIdeas(i) << std::endl;
	}
}

void Cat::setIdea(unsigned int t_pos, std::string t_idea)
{
	m_brain->setIdeas(t_pos, t_idea);
}

Brain* Cat::getBrainPtr(void)
{
	return m_brain;
}
