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

IMateriaSource::~IMateriaSource()
{
	/*Destructor*/
}
