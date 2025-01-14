#include "MateriaSource.hpp"

const int	MateriaSource::m_memorySize = 4;

MateriaSource::MateriaSource() : IMateriaSource()
{
	// std::cout << YELLOW << "MateriaSource default constructor is called" << RESET << std::endl;
	AMateria::initMateriaSlot(m_memory, m_memorySize);
}

MateriaSource::MateriaSource(const MateriaSource &t_src) : IMateriaSource(t_src)
{
	// std::cout << YELLOW << "MateriaSource copy constructor is called" << RESET << std::endl;
	AMateria::initMateriaSlot(m_memory, m_memorySize);
	AMateria::deepCopyMateriaSlot(m_memory, m_memorySize, t_src.m_memory);
}

MateriaSource::~MateriaSource()
{
	// std::cout << YELLOW << "MateriaSource destructor is called" << RESET << std::endl;
	AMateria::destroyMateriaSlot(m_memory, m_memorySize);
}

MateriaSource& MateriaSource::operator=(const MateriaSource &t_rhs)
{
	// std::cout << YELLOW << "MateriaSource assignement operator is called" << RESET << std::endl;
	if (this != &t_rhs)
	{
		AMateria::destroyMateriaSlot(m_memory, m_memorySize);
		AMateria::initMateriaSlot(m_memory, m_memorySize);
		AMateria::deepCopyMateriaSlot(m_memory, m_memorySize, t_rhs.m_memory);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* t_materia)
{
	// std::cout << YELLOW << "MateriaSource learnMateria function is called" << RESET << std::endl;
	for (int i = 0; i < m_memorySize; i++)
	{
		if (m_memory[i] == NULL)
		{
			m_memory[i] = t_materia;
			return;
		}
	}
	std::cout	<< "materia memory reached its maximum capacity: " 
				<< m_memorySize << "\t" << t_materia->getType() 
				<< " materia will be destroy" << std::endl;
	delete t_materia;
}

AMateria* MateriaSource::createMateria(std::string const & t_type)
{
	// std::cout << YELLOW << "MateriaSource createMateria function is called" << RESET << std::endl;
	for (int i = 0; i < m_memorySize; i++)
	{
		if ((m_memory[i] != NULL) && (m_memory[i]->getType() == t_type))
			return m_memory[i]->clone();
	}
	return 0;
}

void MateriaSource::displayMateriaSources(const MateriaSource &m1, const MateriaSource &m2)
{
	unsigned int	size;

	size = MateriaSource::m_memorySize;
	std::cout << "Display MateriaSource memory: " << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << i << ": "; 
		if (m1.m_memory[i] != NULL)
			std::cout << "m1: " << m1.m_memory[i]->getType() << "\t- " << (m1.m_memory[i]) << std::endl;
		else
			std::cout << "m1: " << "null" << std::endl;
		if (m2.m_memory[i] != NULL)
			std::cout << "   m2: " << m2.m_memory[i]->getType() << "\t- " << (m2.m_memory[i]) << std::endl;
		else
			std::cout << "   m2: " << "null" << std::endl;
		std::cout << std::endl;
	}
}
