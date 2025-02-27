#include "MutantStack.hpp"

MutantStack::MutantStack()
{
    /*Constructor*/
}

MutantStack::MutantStack(const MutantStack &t_src)
{
	*this = t_src;

	return ;
}

MutantStack::MutantStack(int const t_n) : m_foo(t_n)
{
	
}

MutantStack::~MutantStack()
{
	/*Destructor*/
}

MutantStack& MutantStack::operator=(const MutantStack &t_rhs)
{
	if (this != &t_rhs)
		this->m_foo = t_rhs.getFoo();
	
	return *this;
}

int MutantStack::getFoo(void) const
{
	return m_foo;
}

std::ostream& operator<<(std::ostream &t_out, MutantStack const &t_rhs)
{
	t_out << t_rhs.getFoo();
	return t_out; 
}