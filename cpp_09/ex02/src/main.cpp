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
		std::cout << "Before : " << input << std::endl;
	} catch (const std::exception &e){
		std::cout << e.what() << std::endl;
		return -1;
	}
	return (0);
}

// shuf -i 1-100 -n 100