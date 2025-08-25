#include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

PmergeMe::PmergeMe()
{
    //  DEFAULT
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{
	//  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
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

std::ostream& operator<<(std::ostream &out, PmergeMe const &rhs)
{
	(void)rhs;
	return out; 
}