#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:

		IMateriaSource();
		IMateriaSource(const IMateriaSource &t_src);
		virtual ~IMateriaSource();

		virtual void learnMateria(AMateria* t_materia) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
