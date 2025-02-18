#include "utils.hpp"

void	testIntArray(void)
{
	std::cout << CYAN << "TEST INT ARRAY\n" << RESET << std::endl;

	Array<int> numbers(INT_ARRAY_SIZE);
	int* mirror = new int[INT_ARRAY_SIZE];

	std::cout << YELLOW << "Display int default value" << RESET << std::endl;
	std::cout << numbers << std::endl;
	srand(time(NULL));
	for (int i = 0; i < INT_ARRAY_SIZE; i++)
	{
		const int value = (rand() % 300);
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << YELLOW << "Create tmp Array and check if it is empty" << RESET << std::endl;
	Array<int> tmp;
	if (tmp.empty())
		std::cout << "tmp is empty\n" << std::endl;
	std::cout << YELLOW << "Copy Numbers into tmp Array" << RESET << std::endl;
	tmp = numbers;
	std::cout << YELLOW << "Copy tmp into test Array" << RESET << std::endl;
	Array<int> test(tmp);

	std::cout << YELLOW << "Check that numbers, tmp and test are the same" << RESET << std::endl;
	for (int i = 0; i < INT_ARRAY_SIZE; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "mirror != numbers" << std::endl;
			break ;
		}
		if (tmp[i] != numbers[i])
		{
			std::cerr << "tmp != numbers" << std::endl;
			break ;
		}
		if (test[i] != numbers[i])
		{
			std::cerr << "test != numbers" << std::endl;
			break ;
		}
		if (i == (INT_ARRAY_SIZE - 1))
			std::cout << "Arrays are equal\n" << std::endl;
	}
	std::cout << YELLOW << "Access Array elements with index out of bounds" << RESET << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		numbers[INT_ARRAY_SIZE] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Update numbers value and check differences" << RESET << std::endl;
	numbers[0] = (rand() % 300);
	numbers[INT_ARRAY_SIZE / 2] = (rand() % 300);
	numbers[INT_ARRAY_SIZE - 2] = (rand() % 300);
	for (int i = 0; i < INT_ARRAY_SIZE; i++)
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

void	testStringArray()
{
	std::cout << CYAN << "TEST STRING ARRAY\n" << RESET << std::endl;

	Array<std::string> strs(STR_ARRAY_SIZE);

	strs[0] = "Hello";
	strs[2] = "world";
	strs[4] = " ! ";

	std::cout << YELLOW << "Display strs Array" << RESET << std::endl;
	std::cout << strs << std::endl;

	Array<std::string> strsCopy(strs);

	std::cout << YELLOW << "Display strsCopy Array" << RESET << std::endl;
	std::cout << strsCopy << std::endl;

	std::cout << MAGENTA << "Update strsCopy" << RESET << std::endl;
	strsCopy[0] = "coucou";
	strsCopy[2] = "le";
	strsCopy[3] = "chat";
	strsCopy[4] = "Botte";

	std::cout << YELLOW << "Display strs Array" << RESET << std::endl;
	std::cout << strs << std::endl;

	std::cout << YELLOW << "Display strsCopy Array" << RESET << std::endl;
	std::cout << strsCopy << std::endl;
}

void	testFloatArray()
{
	std::cout << CYAN << "TEST FLOAT ARRAY\n" << RESET << std::endl;

	Array<float> flt(FLT_ARRAY_SIZE);

	std::cout << YELLOW << "Display float default value" << RESET << std::endl;
	std::cout << flt << std::endl;

	flt[0] = 42.42;
	flt[2] = 8;
	flt[4] = std::numeric_limits<float>::max();
	flt[5] = -(std::numeric_limits<float>::max());
	flt[7] = -53;
	flt[9] = -42.42;

	std::cout << YELLOW << "Display flt Array" << RESET << std::endl;
	std::cout << flt << std::endl;

	Array<float> fltCopy(flt);

	std::cout << YELLOW << "Display fltCopy Array" << RESET << std::endl;
	std::cout << fltCopy << std::endl;

	std::cout << MAGENTA << "Update flt" << RESET << std::endl;
	flt[4] = 42;
	flt[5] = 42;

	std::cout << YELLOW << "Display flt Array" << RESET << std::endl;
	std::cout << flt << std::endl;

	std::cout << YELLOW << "Display fltCopy Array" << RESET << std::endl;
	std::cout << fltCopy << std::endl;
}

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./array 1': Test Array class with type int" << std::endl;
	std::cout << "'./array 2': Test Array class with type string" << std::endl;
	std::cout << "'./array 3': Test Array class with type float" << std::endl;
}

int main(int argc, char **argv)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	if ((argc == 2) && (std::string(argv[1])).size() == 1)
	{
			switch (argv[1][0])
			{
				case '1':
					testIntArray();
					break;

				case '2':
					testStringArray();
					break;

				case '3':
					testFloatArray();
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

