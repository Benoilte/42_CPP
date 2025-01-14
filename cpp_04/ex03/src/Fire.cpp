#include "Fire.hpp"

Fire::Fire() : AMateria("fire")
{
    /*Constructor*/
}

Fire::Fire(const Fire &t_src) : AMateria(t_src)
{
	*this = t_src;
	return ;
}

Fire::~Fire()
{
	/*Destructor*/
}

Fire& Fire::operator=(const Fire &t_rhs)
{
	if (this != &t_rhs)
		AMateria::operator=(t_rhs);
	return *this;
}

AMateria* Fire::clone() const
{
	return (new Fire());
}

void Fire::use(ICharacter& t_target)
{
	std::cout << "* shoots a fire ball at " << t_target.getName() << " *" << std::endl;
}
