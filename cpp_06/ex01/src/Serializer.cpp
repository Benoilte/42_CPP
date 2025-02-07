#include "Serializer.hpp"

Serializer::Serializer()
{
    /*Constructor*/
}

Serializer::Serializer(const Serializer &t_src)
{
	*this = t_src;

	return ;
}

Serializer::~Serializer()
{
	/*Destructor*/
}

Serializer& Serializer::operator=(const Serializer &t_rhs)
{
	(void)t_rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data* t_ptr)
{
	return (reinterpret_cast<uintptr_t>(t_ptr));
}

Data* Serializer::deserialize(uintptr_t t_raw)
{
	return (reinterpret_cast<Data *>(t_raw));
}
