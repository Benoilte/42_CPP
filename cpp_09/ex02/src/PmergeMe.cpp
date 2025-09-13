#include "PmergeMe.hpp"


//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

PmergeMe::PmergeMe()
{
    //  DEFAULT
}

PmergeMe::PmergeMe(const std::vector<int> &vecInput) :
m_vecData(vecInput), m_vecLevel(1), m_timeToSortVecData(0), m_DeqLevel(1), m_timeToSortDeqData(0)
{
	for (std::vector<int>::iterator it = m_vecData.begin() ; it != m_vecData.end(); ++it)
		m_deqData.push_back(*it);
	gettimeofday(&m_startTimer, NULL);
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
size_t 					PmergeMe::getVecSize(void) const { return m_vecData.size(); }
size_t					PmergeMe::getTimeToSortVecData(void) const { return m_timeToSortVecData; }

const std::deque<int>	&PmergeMe::getDeqData(void) const { return m_deqData; }
size_t 					PmergeMe::getDeqSize(void) const { return m_deqData.size(); }
size_t					PmergeMe::getTimeToSortDeqData(void) const { return m_timeToSortDeqData; }

//  ============| SETTERS |=============

//  ============| METHODS |=============

size_t PmergeMe::getDiffTime(const struct timeval &time1, const struct timeval &time2)
{
	size_t	t1, t2;

	t1 = (time1.tv_sec * 1000) + (time1.tv_usec / 1000);
	t2 = (time2.tv_sec * 1000) + (time2.tv_usec / 1000);

	return (t1 - t2);
}

size_t PmergeMe::elapsedTime(const struct timeval &time)
{
	size_t	t1, t2;
	struct timeval now;

	gettimeofday(&now, NULL);

	t1 = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	t2 = (time.tv_sec * 1000) + (time.tv_usec / 1000);

	return (t1 - t2);
}

void	PmergeMe::sort(void)
{
	gettimeofday(&m_startTimer, NULL);
	sortVector();
	m_timeToSortVecData = elapsedTime(m_startTimer);

	gettimeofday(&m_startTimer, NULL);
	sortDeque();
	m_timeToSortDeqData = elapsedTime(m_startTimer);
}

//  ========| MERGE INSERT WITH VECTOR |=========

void	PmergeMe::swapElementVector(size_t b, size_t a, size_t elementSize)
{
	int tmp;

	while (elementSize)
	{
		tmp = m_vecData[b];
		m_vecData[b] = m_vecData[a];
		m_vecData[a] = tmp;
		b--;
		a--;
		elementSize--;
	}

}

void	PmergeMe::sortVector(void)
{
	size_t pairSize = 1 << m_vecLevel;
	size_t elementSize = pairSize / 2;
	(void)elementSize;

	// step 1

	std::cout << "step 1 level: " << m_vecLevel << std::endl;
	if (pairSize <  m_vecData.size())
	{
		for (size_t b = elementSize - 1, a = pairSize - 1; a < m_vecData.size(); b += pairSize, a += pairSize)
		{
			if (m_vecData[b] > m_vecData[a])
				swapElementVector(b, a, elementSize);
		}
		std::cout << *this << std::endl;
		m_vecLevel++;
		sortVector();
	}
	else
	{
		m_vecLevel--;
		return ;
	}

	// step 2 and 3

	std::cout << "step 2 level: " << m_vecLevel << std::endl;
	std::cout << "step 3 level: " << m_vecLevel << std::endl;
	m_vecLevel--;
}

//  ========| MERGE INSERT WITH DEQUE |=========

void	PmergeMe::sortDeque(void)
{

}

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
