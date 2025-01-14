#include "AMateria.hpp"

AMateria::AMateria()
{
	/*Constructor*/
}

AMateria::AMateria(const AMateria &t_src) : m_type(t_src.getType())
{
	(void)t_src;
}

AMateria::AMateria(std::string const & t_type) : m_type(t_type)
{
	/*Copy Constructor*/
}

AMateria::~AMateria()
{
	/*Destructor*/
}

AMateria& AMateria::operator=(const AMateria &t_rhs)
{
	if (this != &t_rhs)
	{

	}
	return *this;
}

void AMateria::use(ICharacter& t_target)
{
	(void)t_target;
	std::cout << "* Base class AMateria::use(ICharacter& t_target)  *";
}

std::string const &AMateria::getType(void) const
{
	return m_type;
}

void AMateria::initMateriaSlot(AMateria **t_slots, unsigned int t_size)
{
	for (unsigned int i = 0; i < t_size; i++)
		t_slots[i] = NULL;
}

void AMateria::deepCopyMateriaSlot(AMateria **t_slots, unsigned int t_size, AMateria *const *t_src)
{
	for (unsigned int i = 0; i < t_size; i++)
	{
		if (t_src[i] != NULL)
			t_slots[i] = t_src[i]->clone();
	}
}

void AMateria::copyMateriaSlot(AMateria **t_slots, unsigned int t_size, AMateria *const *t_src)
{
	for (unsigned int i = 0; i < t_size; i++)
	{
		if (t_src[i] != NULL)
			t_slots[i] = t_src[i];
	}
}

void AMateria::AddMateriaSlot(AMateria ***t_slots, unsigned int &t_size, AMateria *t_materia)
{
	AMateria **tmp;

	if (t_materia == NULL) return;
	t_size++;
	tmp = new AMateria*[t_size];
	copyMateriaSlot(tmp, t_size - 1, *t_slots);
	if ((t_size - 1) > 0)
		delete [] *t_slots;
	tmp[t_size - 1] = t_materia;
	*t_slots = tmp;
}

void AMateria::destroyMateriaSlot(AMateria **t_slots, unsigned int t_size)
{
	for (unsigned int i = 0; i < t_size; i++)
	{
		if (t_slots[i] != NULL)
			delete t_slots[i];
	}
}
