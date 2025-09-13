#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sys/time.h>
# include<cmath>

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
		void	swapElementVector(size_t b, size_t a, size_t elementSize);

		void	sortDeque(void);

	private:

		std::vector<int>	m_vecData;
		size_t				m_vecLevel;
		size_t				m_timeToSortVecData;

		std::deque<int>		m_deqData;
		size_t				m_DeqLevel;
		size_t				m_timeToSortDeqData;

		struct timeval		m_startTimer;

};

std::ostream	&operator<<(std::ostream &out, PmergeMe const &rhs);

#endif
