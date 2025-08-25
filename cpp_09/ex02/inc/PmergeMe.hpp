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
		PmergeMe(const std::deque<int>	&vecInput);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		
		PmergeMe	&operator=(const PmergeMe &rhs);
	
	private:

};

std::ostream	&operator<<(std::ostream &out, PmergeMe const &rhs);

#endif
