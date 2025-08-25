#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <string>

class PmergeMe
{
	
	
	public:
	
		PmergeMe();
		// PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		
		PmergeMe	&operator=(const PmergeMe &rhs);
	
	private:

};

std::ostream	&operator<<(std::ostream &out, PmergeMe const &rhs);

#endif
