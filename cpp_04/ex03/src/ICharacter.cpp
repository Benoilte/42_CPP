#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    /*Constructor*/
}

ICharacter::ICharacter(const ICharacter &t_src)
{
	*this = t_src;

	return ;
}

// ICharacter::ICharacter(int const t_n)
// {
	
// }

ICharacter::~ICharacter()
{
	/*Destructor*/
}

// ICharacter& ICharacter::operator=(const ICharacter &t_rhs)
// {
// 	// if (this != &t_rhs)
	
// 	return *this;
// }
