#include "utils.hpp"

void	testIntArray(void)
{
	std::cout << CYAN << "TEST INT ARRAY\n" << RESET << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	std::cout << YELLOW << "Display int default value" << RESET << std::endl;
	numbers.displayElement();
	std::cout << std::endl;
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = (rand() % 300);
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int> tmp;
	tmp = numbers;
	Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "mirror != numbers" << std::endl;
			return ;
		}
		if (tmp[i] != numbers[i])
		{
			std::cerr << "tmp != numbers" << std::endl;
			return ;
		}
		if (test[i] != numbers[i])
		{
			std::cerr << "test != numbers" << std::endl;
			return ;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	numbers[0] = (rand() % 300);
	numbers[MAX_VAL / 2] = (rand() % 300);
	numbers[MAX_VAL - 2] = (rand() % 300);
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (tmp[i] != numbers[i])
		{
			std::cout << "tmp and numbers didn't have the same value!!" << std::endl;
			std::cout << "tmp[ " << i << " ]:\t" << tmp[i] << std::endl;
			std::cout << "numbers[ " << i << " ]:\t" << numbers[i] << std::endl;
		}
	}
	delete [] mirror;
}

int main(void)
{
	testIntArray();
	return 0;
}

