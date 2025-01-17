#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    /*Constructor*/
}

Ice::Ice(const Ice &t_src) : AMateria(t_src)
{
	*this = t_src;

	return ;
}

Ice::~Ice()
{
	/*Destructor*/
}

Ice& Ice::operator=(const Ice &t_rhs)
{
	if (this != &t_rhs)
		AMateria::operator=(t_rhs);
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& t_target)
{
	std::cout << "* shoots an ice bolt at " << t_target.getName() << " *" << std::endl;
}
