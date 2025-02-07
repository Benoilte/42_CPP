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

Serializer::Serializer(int const t_n) : m_foo(t_n)
{
	
}

Serializer::~Serializer()
{
	/*Destructor*/
}

Serializer& Serializer::operator=(const Serializer &t_rhs)
{
	if (this != &t_rhs)
		this->m_foo = t_rhs.getFoo();
	
	return *this;
}

int Serializer::getFoo(void) const
{
	return m_foo;
}

std::ostream& operator<<(std::ostream &t_out, Serializer const &t_rhs)
{
	t_out << t_rhs.getFoo();
	return t_out; 
}