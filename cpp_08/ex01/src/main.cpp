#include "utils.hpp"

void	test1(void)
{
	std::cout << YELLOW << "Test1: Test given from the subject" << RESET << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test2(void)
{
	std::cout << YELLOW << "Test2: Add too many ints into Span" << RESET << std::endl;

	Span	sp(4);

	sp.addNumber(1);
	std::cout << sp << std::endl;
	sp.addNumber(2);
	std::cout << sp << std::endl;
	sp.addNumber(3);
	std::cout << sp << std::endl;
	sp.addNumber(4);
	std::cout << sp << std::endl;
	sp.addNumber(5);
}

void	test3(void)
{
	std::cout << YELLOW << "Test3: Test shortestSpan function\n" << RESET << std::endl;

	Span	sp(15);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(std::numeric_limits<int>::max());
	std::cout << CYAN << "\nSpan content: " << sp << '\n' << RESET << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(std::numeric_limits<int>::min());
	std::cout << CYAN << "\nSpan content: " << sp << RESET << std::endl;
	std::cout << "\nShortest span: " << sp.shortestSpan() << std::endl; // expected 4294967295
	sp.addNumber(42);
	sp.addNumber(0);
	sp.addNumber(1042);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // expected 42
	sp.addNumber(1043);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // expected 1
	sp.addNumber(1042);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // expected 0
	std::cout << CYAN << "\nSpan content: " << sp << RESET << std::endl;
}

void	test4(void)
{
	std::cout << YELLOW << "Test4: Test longestSpan function\n" << RESET << std::endl;

	Span	sp(15);

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(42);
	std::cout << CYAN << "\nSpan content: " << sp << '\n' << RESET << std::endl;
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(0);
	std::cout << CYAN << "\nSpan content: " << sp << RESET << std::endl;
	std::cout << "\nLongest span: " << sp.longestSpan() << std::endl; // expected 42
	sp.addNumber(1042);
	std::cout << "Longest span: " << sp.longestSpan() << std::endl; // expected 1042
	sp.addNumber(10200);
	sp.addNumber(std::numeric_limits<int>::max());
	std::cout << "Longest span: " << sp.longestSpan() << std::endl; // expected 2147483647
	sp.addNumber(1048);
	sp.addNumber(std::numeric_limits<int>::min());
	std::cout << "Longest span: " << sp.longestSpan() << std::endl; // expected 4294967295
	std::cout << CYAN << "\nSpan content: " << sp << RESET << std::endl;
}

void	test5(void)
{
	std::cout << YELLOW << "Test5: Test span with 10'000 integers\n" << RESET << std::endl;

	Span	sp1(10000);

	sp1.fillWithOrderedNumber();
	std::cout << "Display sp1: " << std::endl;
	std::cout << CYAN << "Span content: " << sp1 << RESET << std::endl;

	Span	sp2(10000);

	sp2.filWithRandomNumber();
	std::cout << "\nDisplay sp2: " << std::endl;
	std::cout << CYAN << "Span content: " << sp2 << RESET << std::endl;

	std::cout << "Shortest span sp1: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span sp1: " << sp1.longestSpan() << std::endl;
	std::cout << "Shortest span sp2: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span sp2: " << sp2.longestSpan() << std::endl;

	Span	sp3(15);

	sp3.fillWithOrderedNumber();
	std::cout << "\nDisplay sp3: " << std::endl;
	std::cout << CYAN << "Span content: " << sp3 << RESET << std::endl;

	Span	sp4(15);

	sp4.filWithRandomNumber();
	std::cout << "\nDisplay sp4: " << std::endl;
	std::cout << CYAN << "Span content: " << sp4 << RESET << std::endl;

	std::cout << "Shortest span sp3: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span sp3: " << sp3.longestSpan() << std::endl;
	std::cout << "Shortest span sp4: " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest span sp4: " << sp4.longestSpan() << std::endl;
}


void	test6(void)
{
	std::cout << YELLOW << "Test6: Test copied span" << RESET << std::endl;

	Span	sp(6);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);

	std::cout << "\nsp content:\t" << sp << std::endl;

	std::cout << CYAN << "\nCopy sp Span" << RESET << std::endl;
	Span		spCopy(sp);
	const Span	spCst(sp);
	Span		spEq(0);

	spEq = sp;
	std::cout << "sp content:\t" << sp << std::endl;
	std::cout << "spCopy content:\t" << spCopy << std::endl;
	std::cout << "spCst content:\t" << spCst << std::endl;
	std::cout << "spEq content:\t" << spEq << std::endl;

	std::cout << CYAN << "\nAdd 42 into sp Span" << RESET << std::endl;
	sp.addNumber(42);
	std::cout << "sp content:\t" << sp << std::endl;
	std::cout << "spCopy content:\t" << spCopy << std::endl;
	std::cout << "spCst content:\t" << spCst << std::endl;
	std::cout << "spEq content:\t" << spEq << std::endl;

	std::cout << CYAN << "\nDisplay shortest and longest span of spCst" << RESET << std::endl;
	std::cout << "Shortest span spCst: " << spCst.shortestSpan() << std::endl;
	std::cout << "Longest span spCst: " << spCst.longestSpan() << std::endl;
	// spCst.addNumber(8);
}

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./span 1': Test given from the subject" << std::endl;
	std::cout << "'./span 2': Add too many ints into Span" << std::endl;
	std::cout << "'./span 3': Test shortestSpan function" << std::endl;
	std::cout << "'./span 4': Test longestSpan function" << std::endl;
	std::cout << "'./span 5': Test span with 10'000 integers" << std::endl;
	std::cout << "'./span 6': Test copied span" << std::endl;
}

int main(int argc, char **argv)
{
	if ((argc == 2) && (std::string(argv[1])).size() == 1)
	{
		try
		{
			switch (argv[1][0])
			{
				case '1':
					test1();
					break;

				case '2':
					test2();
					break;

				case '3':
					test3();
					break;

				case '4':
					test4();
					break;

				case '5':
					test5();
					break;

				case '6':
					test6();
					break;

				default:
					help();
					break;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		help();
	return (0);
}

