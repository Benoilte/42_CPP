#include "PmergeMe.hpp"
#include "Input.hpp"

#include <iostream>
#include <exception>

void	checkCopyConstructor(const Input &input, const PmergeMe &sequence)
{
	std::cout << "\n\n TEST COPY CONSTRUCTOR" << std::endl;
	Input inputCopy(input);
	PmergeMe sequenceCopy(sequence);
	std::cout << "Before:\t [" << sequenceCopy << "]" << std::endl;
	std::cout << "After:\t [" << sequenceCopy << "]" << std::endl;
	std::cout << "Time to process a range of " <<  sequenceCopy.getVecSize() << " elements with std::vector:\t " << sequenceCopy.getTimeToSortVecData() << " us" << std::endl;
	std::cout << "Time to process a range of " <<  sequenceCopy.getDeqSize() << " elements with std::deque:\t " << sequenceCopy.getTimeToSortDeqData() << " us" << std::endl;
	std::cout << "Number of comparisons: " << sequenceCopy.getVecComparisons() << std::endl;
	sequenceCopy.checkAlgo();
}

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

		// Check copy constructor
		// checkCopyConstructor(input, sequence);

	} catch (const std::exception &e){
		std::cout << e.what() << std::endl;
		return -1;
	}
	return (0);
}
