#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria	*m_memory[4];

	public:

		MateriaSource();
		MateriaSource(const MateriaSource &t_src);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &t_rhs);

		virtual void learnMateria(AMateria* t_materia);
		virtual AMateria* createMateria(std::string const & type);

};

#endif
