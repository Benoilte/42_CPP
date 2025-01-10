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
		AMateria(std::string const & type);
		AMateria(const AMateria &t_src);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &t_rhs);

		std::string const &getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
