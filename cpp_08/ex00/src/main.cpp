#include "utils.hpp"

void	testVector(void)
{
	static const int arr[] = {16, 2, 77, 29};
	std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

	try
	{
		std::cout << "First occurence: " << *(easyfind(vec, 16)) << std::endl;
		std::cout << "First occurence: " << *(easyfind(vec, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testConstVector(void)
{
	static const int arr[] = {16, 2, 77, 29};
	const std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

	try
	{
		std::cout << "First occurence: " << *(easyfind(vec, 77)) << std::endl;
		std::cout << "First occurence: " << *(easyfind(vec, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testList(void)
{
	static const int arr[] = {16, 2, 77, 29};
	std::list<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

	try
	{
		std::cout << "First occurence: " << *(easyfind(vec, 2)) << std::endl;
		std::cout << "First occurence: " << *(easyfind(vec, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testListWithChar(void)
{
	static const char arr[] = {'a', 'z', 'b', 'f'};
	std::list<char> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

	try
	{
		std::cout << "First occurence: " << *(easyfind(vec, 'f')) << std::endl;
		std::cout << "First occurence: " << *(easyfind(vec, 'w')) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./easyFind 1': Test Easyfind with vector" << std::endl;
	std::cout << "'./easyFind 2': Test Easyfind with const vector" << std::endl;
	std::cout << "'./easyFind 3': Test Easyfind with list" << std::endl;
	std::cout << "'./easyFind 4': Test Easyfind with list and char" << std::endl;
}

int main(int argc, char **argv)
{
	if ((argc == 2) && (std::string(argv[1])).size() == 1)
	{
			switch (argv[1][0])
			{
				case '1':
					testVector();
					break;

				case '2':
					testConstVector();
					break;

				case '3':
					testList();
					break;

				case '4':
					testListWithChar();
					break;

				default:
					help();
					break;
			}
	}
	else
		help();
	return (0);
}

