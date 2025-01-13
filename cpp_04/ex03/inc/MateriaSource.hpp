#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "colors.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		static const int	m_memorySize;

		AMateria			*m_memory[4];

	public:

		MateriaSource();
		MateriaSource(const MateriaSource &t_src);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &t_rhs);

		virtual void		learnMateria(AMateria* t_materia);
		virtual AMateria	*createMateria(std::string const & type);

		static	void		displayMateriaSources(const MateriaSource &m1, const MateriaSource &cm2);

};

#endif
