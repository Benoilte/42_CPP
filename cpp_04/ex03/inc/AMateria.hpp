#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:

		std::string	m_type;

	public:

		AMateria();
		AMateria(std::string const & t_type);
		AMateria(const AMateria &t_src);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &t_rhs);

		std::string const	&getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& t_target);

		static void			initMateriaSlot(AMateria **t_slots, unsigned int t_size);
		static void			deepCopyMateriaSlot(AMateria **t_slots, unsigned int t_size, AMateria *const *t_src);
		static void			copyMateriaSlot(AMateria **t_slots, unsigned int t_size, AMateria *const *t_src);
		static void			AddMateriaSlot(AMateria ***t_slots, unsigned int &t_size, AMateria *t_materia);
		static void			destroyMateriaSlot(AMateria **t_slots, unsigned int t_size);

};

#endif
