#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sys/time.h>
# include <cmath>
# include <utility>

#include <unistd.h>

class PmergeMe
{


	public:

		PmergeMe();
		PmergeMe(const std::vector<int>	&vecInput);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &rhs);

		const std::vector<int>	&getVecData(void) const;
		size_t					getVecSize(void) const;
		size_t					getTimeToSortVecData(void) const;

		const std::deque<int>	&getDeqData(void) const;
		size_t					getDeqSize(void) const;
		size_t					getTimeToSortDeqData(void) const;

		size_t	getDiffTime(const struct timeval &time1, const struct timeval &time2);
		size_t	elapsedTime(const struct timeval &time);

		void	sort(void);

		void	sortVector(void);

		void	sortDeque(void);

	private:

		typedef std::pair<std::vector<int>, int> t_boundedElement;

		std::vector<int>				m_vecData;
		size_t							m_vecLevel;
		size_t							m_timeToSortVecData;
		std::vector<t_boundedElement>	m_pendVector;
		std::vector<t_boundedElement>	m_mainVector;

		std::deque<int>		m_deqData;
		size_t				m_DeqLevel;
		size_t				m_timeToSortDeqData;

		struct timeval		m_startTimer;

		bool	isOdd(int n);

		void	swapElementVector(size_t b, size_t a, size_t elementSize);
		void	initMainAndPendVector(size_t elementSize);
		void	addElementInPendVector(size_t i, size_t elementSize, int ref);
		void	addElementInMainVector(size_t i, size_t elementSize, int ref);
		void	updateVecData(void);
		void	updateMainVector(int mainIndex);
		void	insertPendInMainVector(void);
		int		binarySearchVector(int n, int lowIndex, int highIndex);
		void	binaryInsertionSortVector(int pendIndex);
		void	printPendVector(void);
		void	printMainVector(void);

};

std::ostream	&operator<<(std::ostream &out, PmergeMe const &rhs);

#endif
