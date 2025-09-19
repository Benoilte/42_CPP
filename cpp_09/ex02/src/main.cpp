#include "PmergeMe.hpp"
#include "Input.hpp"

#include <iostream>
#include <exception>

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::runtime_error("Error");
		Input input(argc, argv);
		PmergeMe sequence(input.getInput());
		std::cout << "Before:\t [" << sequence << "]" << std::endl;
		sequence.sort();
		std::cout << "After:\t [" << sequence << "]" << std::endl;
		std::cout << "Time to process a range of " <<  sequence.getVecSize() << " elements with std::vector:\t " << sequence.getTimeToSortVecData() << " us" << std::endl;
		std::cout << "Time to process a range of " <<  sequence.getDeqSize() << " elements with std::deque:\t " << sequence.getTimeToSortDeqData() << " us" << std::endl;
		std::cout << "Number of comparisons: " << sequence.getVecComparisons() << std::endl;
		sequence.checkAlgo();
	} catch (const std::exception &e){
		std::cout << e.what() << std::endl;
		return -1;
	}
	return (0);
}

// shuf -i 1-100 -n 100
