#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    /*Constructor*/
}

Cure::Cure(const Cure &t_src) : AMateria(t_src)
{
	*this = t_src;
	return ;
}

Cure::~Cure()
{
	/*Destructor*/
}

Cure& Cure::operator=(const Cure &t_rhs)
{
	if (this != &t_rhs)
		AMateria::operator=(t_rhs);
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& t_target)
{
	std::cout << "* heals " << t_target.getName() << "’s wounds *" << std::endl;
}

