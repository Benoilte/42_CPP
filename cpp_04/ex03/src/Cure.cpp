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

void AMateria::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *";
}

// std::ostream& operator<<(std::ostream &t_out, Cure const &t_rhs)
// {
// 	t_out << t_rhs.getFoo();
// 	return t_out;
// }