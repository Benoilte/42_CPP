#include "PmergeMe.hpp"


//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

PmergeMe::PmergeMe()
{
    //  DEFAULT
}

PmergeMe::PmergeMe(const std::vector<int> &vecInput) :
m_vecData(vecInput), m_vecLevel(1), m_timeToSortVecData(0), m_vecComparisons(0),
m_deqLevel(1), m_timeToSortDeqData(0), m_deqComparisons(0)
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
		// Vector member

		this->m_vecData = rhs.m_vecData;
		this->m_vecLevel = rhs.m_vecLevel;
		this->m_timeToSortVecData = rhs.m_timeToSortVecData;
		this->m_pendVector = rhs.m_pendVector;
		this->m_mainVector = rhs.m_mainVector;
		this->m_vecComparisons = rhs.m_vecComparisons;

		// Deque member

		this->m_deqData = rhs.m_deqData;
		this->m_deqLevel = rhs.m_deqLevel;
		this->m_timeToSortDeqData = rhs.m_timeToSortDeqData;
		this->m_pendDeque = rhs.m_pendDeque;
		this->m_mainDeque = rhs.m_mainDeque;
		this->m_deqComparisons = rhs.m_deqComparisons;

		// common member

		this->m_startTimer = rhs.m_startTimer;

	}

	return *this;
}

//  ============| GETTERS |=============

const std::vector<int>	&PmergeMe::getVecData(void) const { return m_vecData; }
size_t 					PmergeMe::getVecSize(void) const { return m_vecData.size(); }
size_t					PmergeMe::getTimeToSortVecData(void) const { return m_timeToSortVecData; }
int						PmergeMe::getVecComparisons(void) const { return m_vecComparisons; }

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

bool PmergeMe::isOdd(int n)
{

    if (n & 1)
        return true;
    else
        return false;
}

int PmergeMe::jacobsthal(int n)
{
    // base case
    if (n == 0)
        return 0;

    // base case
    if (n == 1)
        return 1;

    // recursive step.
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

bool	PmergeMe::checkAlgo(void)
{
	if (checkSequencesEquality() && checkSequencesAscendentOrder() && checkMaximumComparison())
		return true;
	return false;
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

void	PmergeMe::addElementInPendVector(size_t i, size_t elementSize, int ref)
{
	t_boundedElementVector boundedElement;

	while (elementSize)
	{
		boundedElement.first.push_back(m_vecData[i - (elementSize - 1)]);
		elementSize--;
	}
	boundedElement.second = ref;
	m_pendVector.push_back(boundedElement);

}

void	PmergeMe::addElementInMainVector(size_t i, size_t elementSize, int ref)
{
	t_boundedElementVector boundedElement;

	while (elementSize)
	{
		boundedElement.first.push_back(m_vecData[i - (elementSize - 1)]);
		elementSize--;
	}
	boundedElement.second = ref;
	m_mainVector.push_back(boundedElement);
}

void	PmergeMe::printPendVector(void)
{
	std::cout << "Pend: ";
	for (std::vector<t_boundedElementVector>::iterator it = m_pendVector.begin(); it != m_pendVector.end(); it++)
	{
		for (std::vector<int>::iterator el = it->first.begin(); el != it->first.end(); el++)
			std::cout << *el << " ";
		std::cout << " (" << it->second << ") - ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printMainVector(void)
{
	std::cout << "Main: ";
	for (std::vector<t_boundedElementVector>::iterator it = m_mainVector.begin(); it != m_mainVector.end(); it++)
	{
		for (std::vector<int>::iterator el = it->first.begin(); el != it->first.end(); el++)
			std::cout << *el << " ";
		std::cout << " (" << it->second << ") - ";
	}
	std::cout << std::endl;
}

void	PmergeMe::initMainAndPendVector(size_t elementSize)
{
	m_pendVector.clear();
	m_mainVector.clear();
	for (size_t i = elementSize - 1, n = 1; i < m_vecData.size(); i += elementSize, n++)
	{
		if (n == 1 || n == 2)
			addElementInMainVector(i, elementSize, -1);
		else if (isOdd(n))
			addElementInPendVector(i, elementSize, -1);
		else
			addElementInMainVector(i, elementSize, m_pendVector.size() - 1);
	}
	for (size_t i = 0; i < m_mainVector.size(); i++)
	{
		if (m_mainVector[i].second != -1)
			m_pendVector[m_mainVector[i].second].second = i;
	}
}

int	PmergeMe::binarySearchVector(int n, int lowIndex, int highIndex)
{
	m_vecComparisons++;

	if (highIndex <= lowIndex)
		return (n > m_mainVector[lowIndex].first.back()) ? lowIndex + 1 : lowIndex;

	int	mid = (lowIndex + highIndex) / 2;

	if (n > m_mainVector[mid].first.back())
		return binarySearchVector(n, mid + 1, highIndex);

	return binarySearchVector(n, lowIndex, mid - 1);
}

void	PmergeMe::updateVecData(void)
{
	int i = 0;

	for (std::vector<t_boundedElementVector>::iterator it = m_mainVector.begin(); it != m_mainVector.end(); it++)
	{
		for (std::vector<int>::iterator el = it->first.begin(); el != it->first.end(); el++)
		{
			m_vecData[i++] = *el;
		}
	}
}

void	PmergeMe::updateMainVector(int mainIndex)
{
	for (std::vector<t_boundedElementVector>::iterator it = m_mainVector.begin() + mainIndex; it != m_mainVector.end(); it++)
	{
		if (it->second != -1)
			m_pendVector[it->second].second++;
	}
}

void	PmergeMe::binaryInsertionSortVector(int pendIndex)
{
	int highIndex = (m_pendVector[pendIndex].second != -1) ? (m_pendVector[pendIndex].second - 1) : (m_mainVector.size() - 1);
	int	mainIndex = binarySearchVector(m_pendVector[pendIndex].first.back(), 0, highIndex);

	m_mainVector.insert(m_mainVector.begin() + mainIndex, m_pendVector[pendIndex]);
	m_mainVector[mainIndex].second = -1;
	updateMainVector(mainIndex);
}

void	PmergeMe::insertPendInMainVector(void)
{
	int	previousJacobsthalNumber = 1;
	int	jacobsthalNumber = 3;
	int	jacobsthalNumberPosition = 3;
	int elementToInsert;
	int pendIndex;

	while ((previousJacobsthalNumber - 2) < static_cast<int>(m_pendVector.size() - 1))
	{
		if ((jacobsthalNumber - 2) > static_cast<int>(m_pendVector.size() - 1))
		{
			pendIndex = m_pendVector.size() - 1;
			elementToInsert = pendIndex - (previousJacobsthalNumber - 2);
		}
		else
		{
			pendIndex = jacobsthalNumber - 2;
			elementToInsert = jacobsthalNumber - previousJacobsthalNumber;
		}

		while (elementToInsert--)
		{
			binaryInsertionSortVector(pendIndex);
			pendIndex--;
		}
		previousJacobsthalNumber = jacobsthalNumber;
		jacobsthalNumberPosition++;
		jacobsthalNumber = jacobsthal(jacobsthalNumberPosition);
	}

}

void	PmergeMe::sortVector(void)
{
	size_t pairSize = 1 << m_vecLevel;
	size_t elementSize = pairSize / 2;

	if (pairSize <  m_vecData.size())
	{
		for (size_t b = elementSize - 1, a = pairSize - 1; a < m_vecData.size(); b += pairSize, a += pairSize)
		{
			if (m_vecData[b] > m_vecData[a])
				swapElementVector(b, a, elementSize);
			m_vecComparisons++;
		}
		m_vecLevel++;
		sortVector();
	}
	else if (m_vecData.size() == 2)
	{
		m_vecComparisons++;
		if (m_vecData[0] > m_vecData[1])
			swapElementVector(0, 1, 1);
		return ;
	}
	else
	{
		m_vecLevel--;
		return ;
	}

	initMainAndPendVector(elementSize);
	insertPendInMainVector();
	updateVecData();
	m_vecLevel--;
}

//  ========| MERGE INSERT WITH DEQUE |=========

int	PmergeMe::binarySearchDeque(int n, int lowIndex, int highIndex)
{
	m_deqComparisons++;

	if (highIndex <= lowIndex)
		return (n > m_mainDeque[lowIndex].element.back()) ? lowIndex + 1 : lowIndex;

	int	mid = (lowIndex + highIndex) / 2;

	if (n > m_mainDeque[mid].element.back())
		return binarySearchDeque(n, mid + 1, highIndex);

	return binarySearchDeque(n, lowIndex, mid - 1);
}

int	PmergeMe::getMainPairNodeIndex(t_pairNode *boundedElement)
{
	for (size_t i = 0; i < m_mainDeque.size(); i++)
	{
		if (&m_mainDeque[i] == boundedElement)
			return i;
	}
	return m_mainDeque.size() - 1;
}


void	PmergeMe::updateMainDeque(int mainIndex)
{
	for (dqIt it = m_mainDeque.begin() + mainIndex; it != m_mainDeque.end(); it++)
	{
		if (it->boundedElement)
			it->boundedElement->boundedElement = &(*it);
	}
}

void	PmergeMe::binaryInsertionSortDeque(int pendIndex)
{
	int	highIndex = (m_pendDeque[pendIndex].boundedElement) ? (getMainPairNodeIndex(m_pendDeque[pendIndex].boundedElement) - 1) : (m_mainDeque.size() - 1);
	int	mainIndex = binarySearchDeque(m_pendDeque[pendIndex].element.back(), 0, highIndex);

	m_mainDeque.insert(m_mainDeque.begin() + mainIndex, m_pendDeque[pendIndex]);
	m_mainDeque[mainIndex].boundedElement = NULL;
	updateMainDeque(mainIndex);
}

void	PmergeMe::insertPendInMainDeque(void)
{
	int	previousJacobsthalNumber = 1;
	int	jacobsthalNumber = 3;
	int	jacobsthalNumberPosition = 3;
	int elementToInsert;
	int pendIndex;

	while ((previousJacobsthalNumber - 2) < static_cast<int>(m_pendDeque.size() - 1))
	{
		if ((jacobsthalNumber - 2) > static_cast<int>(m_pendDeque.size() - 1))
		{
			pendIndex = m_pendDeque.size() - 1;
			elementToInsert = pendIndex - (previousJacobsthalNumber - 2);
		}
		else
		{
			pendIndex = jacobsthalNumber - 2;
			elementToInsert = jacobsthalNumber - previousJacobsthalNumber;
		}

		while (elementToInsert--)
		{
			binaryInsertionSortDeque(pendIndex);
			pendIndex--;
		}
		previousJacobsthalNumber = jacobsthalNumber;
		jacobsthalNumberPosition++;
		jacobsthalNumber = jacobsthal(jacobsthalNumberPosition);
	}
}

void	PmergeMe::addElementInPendDeque(size_t i, size_t elementSize, s_pairNode *ref)
{
	t_pairNode pairNode;

	while (elementSize)
	{
		pairNode.element.push_back(m_deqData[i - (elementSize - 1)]);
		elementSize--;
	}
	pairNode.boundedElement = ref;
	m_pendDeque.push_back(pairNode);

}

void	PmergeMe::addElementInMainDeque(size_t i, size_t elementSize, s_pairNode *ref)
{
	t_pairNode pairNode;

	while (elementSize)
	{
		pairNode.element.push_back(m_deqData[i - (elementSize - 1)]);
		elementSize--;
	}
	pairNode.boundedElement = ref;
	m_mainDeque.push_back(pairNode);
}

void	PmergeMe::initMainAndPendDeque(size_t elementSize)
{
	m_pendDeque.clear();
	m_mainDeque.clear();
	for (size_t i = elementSize - 1, n = 1; i < m_deqData.size(); i += elementSize, n++)
	{
		if (n == 1 || n == 2)
			addElementInMainDeque(i, elementSize, NULL);
		else if (isOdd(n))
			addElementInPendDeque(i, elementSize, NULL);
		else
			addElementInMainDeque(i, elementSize, &m_pendDeque.back());
	}
	for (size_t i = 0; i < m_mainDeque.size(); i++)
	{
		if (m_mainDeque[i].boundedElement)
			m_mainDeque[i].boundedElement->boundedElement = &m_mainDeque[i];
	}
}

void	PmergeMe::printPendDeque(void)
{
	std::cout << "Pend: ";
	for (dqIt it = m_pendDeque.begin(); it != m_pendDeque.end(); it++)
	{
		for (std::vector<int>::iterator el = it->element.begin(); el != it->element.end(); el++)
			std::cout << *el << " ";
		std::cout << " (";
		if (it->boundedElement)
		{
			for (std::vector<int>::iterator bel = it->boundedElement->element.begin(); bel != it->boundedElement->element.end(); bel++)
				std::cout << *bel << " ";
		}
		else
			std::cout << "X";
		std::cout << ") - ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printMainDeque(void)
{
	std::cout << "Main: ";
	for (dqIt it = m_mainDeque.begin(); it != m_mainDeque.end(); it++)
	{
		for (std::vector<int>::iterator el = it->element.begin(); el != it->element.end(); el++)
			std::cout << *el << " ";
		std::cout << " (";
		if (it->boundedElement)
		{
			for (std::vector<int>::iterator bel = it->boundedElement->element.begin(); bel != it->boundedElement->element.end(); bel++)
				std::cout << *bel << " ";
		}
		else
			std::cout << "X";
		std::cout << ") - ";
	}
	std::cout << std::endl;
}

void	PmergeMe::swapElementDeque(size_t b, size_t a, size_t elementSize)
{
	int tmp;

	while (elementSize)
	{
		tmp = m_deqData[b];
		m_deqData[b] = m_deqData[a];
		m_deqData[a] = tmp;
		b--;
		a--;
		elementSize--;
	}
}

void	PmergeMe::updateDeqData(void)
{
	int i = 0;

	for (dqIt it = m_mainDeque.begin(); it != m_mainDeque.end(); it++)
	{
		for (std::vector<int>::iterator el = it->element.begin(); el != it->element.end(); el++)
		{
			m_deqData[i++] = *el;
		}
	}
}

void	PmergeMe::sortDeque(void)
{
	size_t pairSize = 1 << m_deqLevel;
	size_t elementSize = pairSize / 2;

	if (pairSize <  m_deqData.size())
	{
		for (size_t b = elementSize - 1, a = pairSize - 1; a < m_deqData.size(); b += pairSize, a += pairSize)
		{
			m_deqComparisons++;
			if (m_deqData[b] > m_deqData[a])
				swapElementDeque(b, a, elementSize);
		}
		m_deqLevel++;
		sortDeque();
	}
	else if (m_deqData.size() == 2)
	{
		m_deqComparisons++;
		if (m_deqData[0] > m_deqData[1])
			swapElementDeque(0, 1, 1);
		return ;
	}
	else
	{
		m_deqLevel--;
		return ;
	}

	initMainAndPendDeque(elementSize);
	insertPendInMainDeque();
	updateDeqData();
	m_deqLevel--;
}

//  ========| TEST SEQUENCES |=========

bool	PmergeMe::checkSequencesEquality(void)
{
	if (m_vecData.size() != m_deqData.size())
	{
		std::cout << RED << "ERROR: Sequences are not equal (size)" << RESET << std::endl;
		return false;
	}

	if (m_vecComparisons != m_deqComparisons)
	{
		std::cout << RED << "ERROR: Sequences are not equal (comparisons)" << RESET << std::endl;
		return false;
	}
	
	for (size_t i = 0; i < m_vecData.size(); i++)
	{
		if (m_vecData[i] != m_deqData[i])
		{
			std::cout << RED << "ERROR: Sequences are not equal (sequence)" << RESET << std::endl;
			return false;
		}
	}

	std::cout << GREEN << "Sequences are equal" << RESET << std::endl;
	return true;
}

bool	PmergeMe::checkSequencesAscendentOrder(void)
{
	for (size_t i = 0; i < (m_vecData.size() - 1); i++)
	{
		if (m_vecData[i] > m_vecData[i + 1])
		{
			std::cout << RED << "ERROR: Vector sequence is not sorted in ascendent order" << RESET << std::endl;
			return false;
		}
	}

	for (size_t i = 0; i < (m_deqData.size() - 1); i++)
	{
		if (m_deqData[i] > m_deqData[i + 1])
		{
			std::cout << RED << "ERROR: Deque sequence is not sorted in ascendent order" << RESET << std::endl;
			return false;
		}
	}

	std::cout << GREEN << "Sequences are sorted in ascendent order" << RESET << std::endl;
	return true;
}

bool	PmergeMe::checkMaximumComparison(void)
{
    int sum = 0;
	int n = m_vecData.size();
	bool success = true;

    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }

	if (m_vecComparisons > sum)
	{
		std::cout << RED << "ERROR: Too many comparisons for FJ Algorithm with vector: " << m_deqComparisons << " instead of: " << sum << RESET << std::endl;
		success = false;
	}
	
	if (m_deqComparisons > sum)
	{
		std::cout << RED << "ERROR: Too many comparisons for FJ Algorithm with deque: " << m_deqComparisons << " instead of: " << sum << RESET << std::endl;
		success = false;
	}

	if ((m_deqComparisons <= sum) && (m_vecComparisons <= sum))
		std::cout << GREEN << "Maximum of comparisons respected: " << sum << " Comparisons effective: " << m_vecComparisons << RESET << std::endl;
	return success;
}

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, PmergeMe const &rhs)
{
	for (std::deque<int>::const_iterator it = rhs.getDeqData().begin() ; it != rhs.getDeqData().end(); ++it)
		out << *it << ' ';
	return out;
}
