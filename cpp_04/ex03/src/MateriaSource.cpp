#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		m_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &t_src) : IMateriaSource(t_src)
{
	for (int i = 0; i < 4; i++)
	{
		if (t_src.m_memory[i] == NULL)
			m_memory[i] = t_src.m_memory[i]->clone();
	}
	return ;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_memory[i] != NULL)
			delete m_memory[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &t_rhs)
{
	if (this != &t_rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_memory[i] != NULL)
				delete m_memory[i];
			m_memory[i] = t_rhs.m_memory[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* t_materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_memory[i] == NULL)
			m_memory[i] = t_materia;
	}
	delete t_materia;
}

AMateria* MateriaSource::createMateria(std::string const & t_type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_memory[i]->getType() == t_type)
			return m_memory[i]->clone();
	}
	return 0;
}
