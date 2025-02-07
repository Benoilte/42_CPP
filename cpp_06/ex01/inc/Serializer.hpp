#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>

class Serializer
{
	private:
	
		// PRIVATE ATTRIBUTE //

		int	m_foo;

		// PRIVATE MEMBER FUNCTION //

	public:

		// CONSTRUCTOR //

		Serializer();
		Serializer(int const t_n);
		Serializer(const Serializer &t_src);

		// DESTRUCTOR //

		~Serializer();

		// OPERATOR OVERLOAD //

		Serializer	&operator=(const Serializer &t_rhs);

		// GETTER //

		int		getFoo(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

};

std::ostream	&operator<<(std::ostream &t_out, Serializer const &t_rhs);

#endif
