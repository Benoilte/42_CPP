#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# include "data.hpp"

class Serializer
{
	private:

		// CONSTRUCTOR //

		Serializer();
		Serializer(const Serializer &t_src);

		// DESTRUCTOR //

		~Serializer();

		// OPERATOR OVERLOAD //

		Serializer	&operator=(const Serializer &t_rhs);
	
		// PRIVATE ATTRIBUTE //

		// PRIVATE MEMBER FUNCTION //

	public:

		// GETTER //

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		// PUBLIC STATIC FUNCTION //

		static uintptr_t	serialize(Data* t_ptr);
		static Data*		deserialize(uintptr_t t_raw);
};

#endif
