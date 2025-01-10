#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:

		IMateriaSource();
		// IMateriaSource(int const t_n);
		IMateriaSource(const IMateriaSource &t_src);
		virtual ~IMateriaSource();

		// IMateriaSource	&operator=(const IMateriaSource &t_rhs);

		virtual void learnMateria(AMateria* t_materia) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
