#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor is called" << std::endl;
}

Brain::Brain(const Brain &t_src)
{
	std::cout << "Brain copy constructor is called" << std::endl;
	*this = t_src;

	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain &t_rhs)
{
	if (this != &t_rhs)
	{
		for (int i = 0; i < 100; i++)
			this->setIdeas(i, t_rhs.getIdeas(i));
	}

	return *this;
}

const std::string Brain::getIdeas(unsigned int t_pos) const
{
	if (t_pos < 100)
		return m_ideas[t_pos];
	return "";
}

void Brain::setIdeas(unsigned int t_pos, std::string t_idea)
{
	if (t_pos < 100)
		m_ideas[t_pos] = t_idea;
}
