#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    /*Constructor*/
}

IMateriaSource::IMateriaSource(const IMateriaSource &t_src)
{
	*this = t_src;

	return ;
}

// IMateriaSource::IMateriaSource(int const t_n)
// {
	
// }

IMateriaSource::~IMateriaSource()
{
	/*Destructor*/
}

// IMateriaSource& IMateriaSource::operator=(const IMateriaSource &t_rhs)
// {
// 	// if (this != &t_rhs)
	
// 	return *this;
// }
