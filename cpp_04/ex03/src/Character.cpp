#include "Character.hpp"

Character::Character() : ICharacter()
{
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(const Character &t_src) : ICharacter()
{
	for (int i = 0; i < 4; i++)
	{
		if (t_src.m_inventory[i] != NULL)
			m_inventory[i] = t_src.m_inventory[i]->clone();
	}
	return ;
}

Character::Character(std::string const t_name) : ICharacter(), m_name(t_name)
{
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] != NULL)
			delete m_inventory[i];
	}
}

Character& Character::operator=(const Character &t_rhs)
{
	if (this != &t_rhs)
		this->m_name = t_rhs.getName();
	
	return *this;
}

std::string const& Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria* t_materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
			m_inventory[i] = t_materia;
	}
}

void Character::unequip(int t_idx)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == t_idx)
			delete m_inventory[i];
	}
}

void Character::use(int t_idx, ICharacter& t_target)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == t_idx)
			m_inventory[i]->use(t_target);
	}
}
