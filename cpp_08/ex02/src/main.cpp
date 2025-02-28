#include "utils.hpp"

void	testMutantStack(void)
{
	MutantStack<int> mstack;

	std::cout << CYAN << "Push 5 and 42 into mstack" << RESET << std::endl;
	mstack.push(5);
	mstack.push(42);

	std::cout << CYAN << "\ndisplay last element: Sould be 42" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << CYAN << "\nPop last element from mstack" << RESET << std::endl;
	mstack.pop();

	std::cout << CYAN << "\ndisplay last element: Sould be 5" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << CYAN << "\ndisplay mstack size: Sould be 1" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;

	std::cout << CYAN << "\nPush 3, 48, 1023, 458, 7 into mstack" << RESET << std::endl;
	mstack.push(3);
	mstack.push(48);
	mstack.push(1023);
	mstack.push(458);
	mstack.push(7);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	iterateThroughStack(it, ite, "\nIterate through mstack and display all element");

	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	iterateThroughStack(cit, cite, "\nDo the same with const iterator");

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	iterateThroughStack(rit, rite, "\nDo the same with reverse iterator");

	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	iterateThroughStack(crit, crite, "\nDo the same with reverse const iterator");
}

void	testCopyMutantStack(void)
{
	MutantStack<int> mstack;

	mstack.push(0);
	mstack.push(4);
	mstack.push(8);
	mstack.push(12);
	mstack.push(-42);
	mstack.push(1042);

	std::cout << CYAN << "Copy different element from mstack and display last one" << RESET << std::endl;
	std::stack<int> s(mstack);
	MutantStack<int> mstackCopy(mstack);
	MutantStack<int> mstackEquality;
	mstackEquality = mstack;

	std::cout << "mstack.top():\t\t" << mstack.top() << std::endl;
	std::cout << "s.top():\t\t" << s.top() << std::endl;
	std::cout << "mstackCopy.top():\t" << mstackCopy.top() << std::endl;
	std::cout << "mstackEquality.top():\t" << mstackEquality.top() << std::endl;

	std::cout << CYAN << "\nPop last element of s" << RESET << std::endl;
	s.pop();

	std::cout << "mstack.top():\t\t" << mstack.top() << std::endl;
	std::cout << "s.top():\t\t" << s.top() << std::endl;
	std::cout << "mstackCopy.top():\t" << mstackCopy.top() << std::endl;
	std::cout << "mstackEquality.top():\t" << mstackEquality.top() << std::endl;

	std::cout << CYAN << "\nPop last element of mstackCopy" << RESET << std::endl;
	mstackCopy.pop();

	std::cout << "mstack.top():\t\t" << mstack.top() << std::endl;
	std::cout << "s.top():\t\t" << s.top() << std::endl;
	std::cout << "mstackCopy.top():\t" << mstackCopy.top() << std::endl;
	std::cout << "mstackEquality.top():\t" << mstackEquality.top() << std::endl;

	std::cout << CYAN << "\nPop last element of mstackEquality" << RESET << std::endl;
	mstackEquality.pop();

	std::cout << "mstack.top():\t\t" << mstack.top() << std::endl;
	std::cout << "s.top():\t\t" << s.top() << std::endl;
	std::cout << "mstackEquality.top():\t" << mstackEquality.top() << std::endl;
	std::cout << "mstackEquality.top():\t" << mstackEquality.top() << std::endl;
}

void	testFromSubject(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

void	testFromSubjectWithList(void)
{
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	testMutantStackWithVector(void)
{
	MutantStack<int, std::vector<int> > mstack;

	std::cout << CYAN << "Push 5 and 42 into mstack" << RESET << std::endl;
	mstack.push(5);
	mstack.push(42);

	std::cout << CYAN << "\ndisplay last element: Sould be 42" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << CYAN << "\nPop last element from mstack" << RESET << std::endl;
	mstack.pop();

	std::cout << CYAN << "\ndisplay last element: Sould be 5" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << CYAN << "\ndisplay mstack size: Sould be 1" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;

	std::cout << CYAN << "\nPush 3, 48, 1023, 458, 7 into mstack" << RESET << std::endl;
	mstack.push(3);
	mstack.push(48);
	mstack.push(1023);
	mstack.push(458);
	mstack.push(7);

	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	iterateThroughStack(it, ite, "\nIterate through mstack and display all element");

	MutantStack<int, std::vector<int> >::const_iterator cit = mstack.begin();
	MutantStack<int, std::vector<int> >::const_iterator cite = mstack.end();
	iterateThroughStack(cit, cite, "\nDo the same with const iterator");

	MutantStack<int, std::vector<int> >::reverse_iterator rit = mstack.rbegin();
	MutantStack<int, std::vector<int> >::reverse_iterator rite = mstack.rend();
	iterateThroughStack(rit, rite, "\nDo the same with reverse iterator");

	MutantStack<int, std::vector<int> >::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int, std::vector<int> >::const_reverse_iterator crite = mstack.rend();
	iterateThroughStack(crit, crite, "\nDo the same with reverse const iterator");
}

void	help()
{
	std::cout << "Available command: " << std::endl;
	std::cout << "'./mutantAbomination 1': Test MutantStack class" << std::endl;
	std::cout << "'./mutantAbomination 2': Test copy constructor and assignement of MutantStack class" << std::endl;
	std::cout << "'./mutantAbomination 3': Test From the subject" << std::endl;
	std::cout << "'./mutantAbomination 4': Test From the subject replaced by list containers" << std::endl;
	std::cout << "'./mutantAbomination 5': Test MutantStack class With vector instead of default deque" << std::endl;
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

				case '2':
					testCopyMutantStack();
					break;

				case '3':
					testFromSubject();
					break;

				case '4':
					testFromSubjectWithList();
					break;

				case '5':
					testMutantStackWithVector();
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

