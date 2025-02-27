#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>

class MutantStack
{
	private:
	
		// PRIVATE ATTRIBUTE //

		int	m_foo;

		// PRIVATE MEMBER FUNCTION //

	public:

		// CONSTRUCTOR //

		MutantStack();
		MutantStack(int const t_n);
		MutantStack(const MutantStack &t_src);

		// DESTRUCTOR //

		~MutantStack();

		// OPERATOR OVERLOAD //

		MutantStack	&operator=(const MutantStack &t_rhs);

		// GETTER //

		int		getFoo(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

};

std::ostream	&operator<<(std::ostream &t_out, MutantStack const &t_rhs);

#endif
