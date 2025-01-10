#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "ICharacter.hpp"

class AMateria : private IMateriaSource
{
	private:

		AMateria	*m_memory[4];

	protected:
	
		std::string	m_type;

	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &t_src);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &t_rhs);

		std::string const &getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

};

#endif
