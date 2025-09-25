#include "RPN.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

RPN::RPN()
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

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, RPN const &rhs)
{
	(void)rhs;
	return out; 
}