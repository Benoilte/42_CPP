#include "Character.hpp"

const int	Character::m_inventorySize = 4;

Character::Character() : ICharacter()
{
	AMateria::initMateriaSlot(m_inventory, m_inventorySize);
	m_unused = NULL;
	m_unusedSize = 0;
}

Character::Character(const Character &t_src) : ICharacter(), m_name(t_src.getName() + "_copy")
{
	AMateria::initMateriaSlot(m_inventory, m_inventorySize);
	AMateria::deepCopyMateriaSlot(m_inventory, m_inventorySize, t_src.m_inventory);
	m_unusedSize = t_src.m_unusedSize;
	if (m_unusedSize > 0)
	{
		m_unused = new AMateria*[m_unusedSize];
		AMateria::deepCopyMateriaSlot(m_unused, m_unusedSize, t_src.m_unused);
	}
	else
		m_unused = NULL;
}

Character::Character(std::string const t_name) : ICharacter(), m_name(t_name)
{
	AMateria::initMateriaSlot(m_inventory, m_inventorySize);
	m_unused = NULL;
	m_unusedSize = 0;
}

Character::~Character()
{
	AMateria::destroyMateriaSlot(m_inventory, m_inventorySize);
	AMateria::destroyMateriaSlot(m_unused, m_unusedSize);
	if (m_unusedSize > 0)
		delete [] m_unused;
}

Character& Character::operator=(const Character &t_rhs)
{
	if (this != &t_rhs)
	{
		AMateria::destroyMateriaSlot(m_inventory, m_inventorySize);
		AMateria::initMateriaSlot(m_inventory, m_inventorySize);
		AMateria::deepCopyMateriaSlot(m_inventory, m_inventorySize, t_rhs.m_inventory);
		if (m_unusedSize > 0)
		{
			AMateria::destroyMateriaSlot(m_unused, m_unusedSize);
			delete [] m_unused;
		}
		m_unusedSize = t_rhs.m_unusedSize;
		if (m_unusedSize > 0)
		{
			m_unused = new AMateria*[m_unusedSize];
			AMateria::deepCopyMateriaSlot(m_unused, m_unusedSize, t_rhs.m_unused);
		}
		else
			m_unused = NULL;
	}
	return *this;
}

std::string const& Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria* t_materia)
{
	if (t_materia == NULL) return;
	for (int i = 0; i < m_inventorySize; i++)
	{
		if (m_inventory[i] == NULL)
		{
			m_inventory[i] = t_materia;
			return ;
		}
	}
	AMateria::AddMateriaSlot(&m_unused, m_unusedSize, t_materia);
}

void Character::unequip(int t_idx)
{
	for (int i = 0; i < m_inventorySize; i++)
	{
		if ((i == t_idx) && (m_inventory[i] != NULL))
		{
			AMateria::AddMateriaSlot(&m_unused, m_unusedSize, m_inventory[i]);
			m_inventory[i] = NULL;
		}
	}
}

void Character::use(int t_idx, ICharacter& t_target)
{
	for (int i = 0; i < m_inventorySize; i++)
	{
		if ((i == t_idx) && (m_inventory[i] != NULL))
			m_inventory[i]->use(t_target);
	}
}

void Character::displayCharacters(const Character &c1)
{
	unsigned int	size;

	std::cout << YELLOW << "c1: " << c1.getName() << RESET << std::endl;
	size = Character::m_inventorySize;
	std::cout << "Display characters inventory: " << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << i << ": "; 
		if (c1.m_inventory[i] != NULL)
			std::cout << "c1: " << c1.m_inventory[i]->getType() << "\t- " << (c1.m_inventory + i) << std::endl;
		else 
			std::cout << "c1: " << "null" << std::endl;
		std::cout << std::endl;
	}
	if (c1.m_unusedSize > 0)
		std::cout << "Display characters unused materia: " << std::endl;
	for (unsigned int i = 0; i < c1.m_unusedSize; i++)
	{
		std::cout << i << ": "; 
		if (i < c1.m_unusedSize)
			std::cout << "c1: " << c1.m_unused[i]->getType() << "\t- " << (c1.m_unused + i) << std::endl;
		else 
			std::cout << "c1: " << "null" << std::endl;
		std::cout << std::endl;
	}
}

void Character::displayCharacters(const Character &c1, const Character &c2)
{
	unsigned int	size;

	std::cout << YELLOW << "c1: " << c1.getName() << "\nc2: " << c2.getName() << RESET << std::endl;
	size = Character::m_inventorySize;
	std::cout << "Display characters inventory: " << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << i << ": "; 
		if (c1.m_inventory[i] != NULL)
			std::cout << "c1: " << c1.m_inventory[i]->getType() << "\t- " << (c1.m_inventory + i) << std::endl;
		else 
			std::cout << "c1: " << "null" << std::endl;
		if (c2.m_inventory[i] != NULL)
			std::cout << "   c2: " << c2.m_inventory[i]->getType() << "\t- " << (c2.m_inventory + i) << std::endl;
		else 
			std::cout << "   c2: " << "null" << std::endl;
		std::cout << std::endl;
	}
	size = (c1.m_unusedSize > c2.m_unusedSize) ? c1.m_unusedSize : c2.m_unusedSize;
	if (size > 0)
		std::cout << "Display characters unused materia: " << std::endl;
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << i << ": "; 
		if (i < c1.m_unusedSize)
			std::cout << "c1: " << c1.m_unused[i]->getType() << "\t- " << (c1.m_unused + i) << std::endl;
		else 
			std::cout << "c1: " << "null" << std::endl;
		if (i < c2.m_unusedSize)
			std::cout << "   c2: " << c2.m_unused[i]->getType() << "\t- " << (c2.m_unused + i) << std::endl;
		else 
			std::cout << "   c2: " << "null" << std::endl;
		std::cout << std::endl;
	}
}
