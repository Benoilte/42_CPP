#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(const AMateria &t_src)
{
	(void)t_src;
}

AMateria::AMateria(std::string const & t_type) : m_type(t_type)
{

}

AMateria::~AMateria()
{

}

AMateria& AMateria::operator=(const AMateria &t_rhs)
{
	if (this != &t_rhs)
		this->m_type = t_rhs.getType();
	return *this;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "* Base class AMateria::use(ICharacter& target)  *";
}

std::string const &AMateria::getType(void) const
{
	return m_type;
}
