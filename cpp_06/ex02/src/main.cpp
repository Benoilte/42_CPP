#include "utils.hpp"

Base* generate(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	A	*aPtr;
	B	*bPtr;
	C	*cPtr;

	aPtr = dynamic_cast<A *>(p);
	if (aPtr != NULL)
	{
		std::cout << "p point to object A" << std::endl;
		return ;
	}

	bPtr = dynamic_cast<B *>(p);
	if (bPtr != NULL)
	{
		std::cout << "p point to object B" << std::endl;
		return ;
	}

	cPtr = dynamic_cast<C *>(p);
	if (cPtr != NULL)
	{
		std::cout << "p point to object C" << std::endl;
		return ;
	}
	
	std::cout << "p point to unrelated object" << std::endl;
}

void identify(Base& p)
{
	(void)p;
	return ;
}

void	test1()
{
	std::cout << YELLOW << "test identify function with pointer as argument" << RESET << std::endl;

	Base	*basePtr1 = generate();
	sleep(1);
	Base	*basePtr2 = generate();
	sleep(1);
	Base	*basePtr3 = generate();
	sleep(1);
	Base	*basePtr4 = new Base();

	identify(basePtr1);
	identify(basePtr2);
	identify(basePtr3);
	identify(basePtr4);

	delete basePtr1;
	delete basePtr2;
	delete basePtr3;
	delete basePtr4;
}

void	test2()
{
	std::cout << YELLOW << "test identify function with reference as argument" << RESET << std::endl;

	Base	*basePtr1 = generate();
	sleep(1);
	Base	*basePtr2 = generate();
	sleep(1);
	Base	*basePtr3 = generate();
	sleep(1);
	Base	*basePtr4 = new Base();

	identify(basePtr1);
	identify(basePtr2);
	identify(basePtr3);
	identify(basePtr4);

	delete basePtr1;
	delete basePtr2;
	delete basePtr3;
	delete basePtr4;
}

int	main(void)
{
	test1();
	test2();
	return (0);
}

