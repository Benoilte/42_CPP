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

ICharacter::~ICharacter()
{
	/*Destructor*/
}
