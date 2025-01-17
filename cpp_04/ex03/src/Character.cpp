#include "Character.hpp"

const int		Character::m_inventorySize = 4;
AMateria		**Character::m_unused = NULL;
unsigned int	Character::m_unusedSize = 0;
unsigned int	Character::m_characterCount = 0;

Character::Character() : ICharacter()
{
	m_characterCount++;
	AMateria::initMateriaSlot(m_inventory, m_inventorySize);
}

Character::Character(const Character &t_src) : ICharacter(), m_name(t_src.getName() + "_copy")
{
	m_characterCount++;
	AMateria::initMateriaSlot(m_inventory, m_inventorySize);
	AMateria::deepCopyMateriaSlot(m_inventory, m_inventorySize, t_src.m_inventory);
}

Character::Character(std::string const t_name) : ICharacter(), m_name(t_name)
{
	m_characterCount++;
	AMateria::initMateriaSlot(m_inventory, m_inventorySize);
}

Character::~Character()
{
	m_characterCount--;
	AMateria::destroyMateriaSlot(m_inventory, m_inventorySize);
	if ((m_characterCount == 0) && (m_unusedSize > 0))
	{
		AMateria::destroyMateriaSlot(m_unused, m_unusedSize);
		delete [] m_unused;
	}
}

Character& Character::operator=(const Character &t_rhs)
{
	if (this != &t_rhs)
	{
		AMateria::destroyMateriaSlot(m_inventory, m_inventorySize);
		AMateria::initMateriaSlot(m_inventory, m_inventorySize);
		AMateria::deepCopyMateriaSlot(m_inventory, m_inventorySize, t_rhs.m_inventory);
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
			std::cout << "c1: " << c1.m_inventory[i]->getType() << "\t- " << (c1.m_inventory[i]) << std::endl;
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
			std::cout << "c1: " << c1.m_inventory[i]->getType() << "\t- " << (c1.m_inventory[i]) << std::endl;
		else
			std::cout << "c1: " << "null" << std::endl;
		if (c2.m_inventory[i] != NULL)
			std::cout << "   c2: " << c2.m_inventory[i]->getType() << "\t- " << (c2.m_inventory[i]) << std::endl;
		else
			std::cout << "   c2: " << "null" << std::endl;
		std::cout << std::endl;
	}
}

void Character::displayUnusedMateria()
{
	std::cout << MAGENTA << "Display unused materia:" << RESET << std::endl;
	for (unsigned int i = 0; i < m_unusedSize; i++)
		std::cout << i << ": " << m_unused[i]->getType() << "\t- " << m_unused[i] << std::endl;
}
