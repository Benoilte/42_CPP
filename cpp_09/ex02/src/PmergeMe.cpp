#include "PmergeMe.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

PmergeMe::PmergeMe()
{
    //  DEFAULT
}

PmergeMe::PmergeMe(const std::vector<int> &vecInput) :
m_vecData(vecInput)
{
	for (std::vector<int>::iterator it = m_vecData.begin() ; it != m_vecData.end(); ++it)
		m_deqData.push_back(*it);
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

const std::vector<int>	&PmergeMe::getVecData(void) const { return m_vecData; }
const std::deque<int>	&PmergeMe::getDeqData(void) const { return m_deqData; }

//  ============| SETTERS |=============

//  ============| METHODS |=============

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, PmergeMe const &rhs)
{
	// out << "Vector data:\t";
	for (std::vector<int>::const_iterator it = rhs.getVecData().begin() ; it != rhs.getVecData().end(); ++it)
		out << *it << ' ';
	// out << "\nDeque data:\t";
	// for (std::deque<int>::const_iterator it = rhs.getDeqData().begin() ; it != rhs.getDeqData().end(); ++it)
	// 	out << *it << ' ';
	return out;
}