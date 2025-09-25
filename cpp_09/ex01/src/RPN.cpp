#include "RPN.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

RPN::RPN()
{
    //  DEFAULT
}

RPN::RPN(const std::string &str) : m_rpnSequence(str)
{
    //  DEFAULT
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
	//  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======

RPN& RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		;
	}

	return *this;
}

//  ============| GETTERS |=============

//  ============| SETTERS |=============

//  ============| METHODS |=============

int	RPN::compute(void)
{
	return 42;
}
//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, RPN const &rhs)
{
	(void)rhs;
	return out;
}
