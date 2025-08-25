#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
	
	
	public:
	
		PmergeMe();
		PmergeMe(const std::vector<int>	&vecInput);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		
		PmergeMe	&operator=(const PmergeMe &rhs);

		const std::vector<int>	&getVecData(void) const;
		const std::deque<int>	&getDeqData(void) const;
	
	private:

		std::vector<int>	m_vecData;
		std::deque<int>		m_deqData;

};

std::ostream	&operator<<(std::ostream &out, PmergeMe const &rhs);

#endif
