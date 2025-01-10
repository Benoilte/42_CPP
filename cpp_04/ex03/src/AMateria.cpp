#include "AMateria.hpp"

AMateria::AMateria() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		m_memory[i] = NULL;
}

AMateria::AMateria(const AMateria &t_src) : IMateriaSource(t_src)
{
	for (int i = 0; i < 4; i++)
	{
		if (t_src.m_memory[i] != NULL)
			m_memory[i] = t_src.m_memory[i]->clone();
	}
	return ;
}

AMateria::AMateria(std::string const & t_type) : IMateriaSource(), m_type(t_type)
{
	for (int i = 0; i < 4; i++)
		m_memory[i] = NULL;
}

AMateria::~AMateria()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_memory[i] != NULL)
			delete m_memory[i];
	}
}

AMateria& AMateria::operator=(const AMateria &t_rhs)
{
	if (this != &t_rhs)
		this->m_type = t_rhs.getType();
	return *this;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* Base class AMateria::use(ICharacter& target)  *";
}

std::string const &AMateria::getType(void) const
{
	return m_type;
}

void AMateria::learnMateria(AMateria* t_materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_memory[i] == NULL)
			m_memory[i] = t_materia;
	}
	delete t_materia;
}

AMateria* AMateria::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_memory[i]->getType() == type)
			return m_memory[i]->clone();
	}
	return 0;
}
