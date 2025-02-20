#include "utils.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	static const int arr[] = {16,2,77,29};
	std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));
	try
	{
		std::cout << "First occurence: " << easyfind(vec, 16) << std::endl;
		std::cout << "First occurence: " << easyfind(vec, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

