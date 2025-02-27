#include "utils.hpp"

void	testMutantStack(void)
{
	MutantStack<int, std::stack<int> > mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(42);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::iterator it;
	MutantStack<int>::iterator ite;

	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	std::stack<int, std::stack<int> > s(mstack);

	std::cout << mstack.top() << std::endl;

	// s.top() = 8;

	std::cout << s.top() << std::endl;
	// std::cout << mstack.getHead() << std::endl;
}

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./mutantAbomination 1': Test MutantStack class" << std::endl;
	// std::cout << "'./mutantAbomination 2': Test Array class with type string" << std::endl;
}

int main(int argc, char **argv)
{
	if ((argc == 2) && (std::string(argv[1])).size() == 1)
	{
			switch (argv[1][0])
			{
				case '1':
					testMutantStack();
					break;

				// case '2':
				// 	testStringArray();
				// 	break;

				default:
					help();
					break;
			}
	}
	else
		help();
	return (0);
}

