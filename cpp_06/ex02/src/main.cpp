#include "utils.hpp"

Base* generate(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
	{
		std::cout << CYAN << "Object A is created" << RESET << std::endl;
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << CYAN << "Object B is created" << RESET << std::endl;
		return (new B());
	}
	else
	{
		std::cout << CYAN << "Object C is created" << RESET << std::endl;
		return (new C());
	}
}

void identify(Base* p)
{
	A	*aPtr;
	B	*bPtr;
	C	*cPtr;

	aPtr = dynamic_cast<A *>(p);
	if (aPtr != NULL)
	{
		std::cout << "pointer p point to object A" << std::endl;
		return ;
	}

	bPtr = dynamic_cast<B *>(p);
	if (bPtr != NULL)
	{
		std::cout << "pointer p point to object B" << std::endl;
		return ;
	}

	cPtr = dynamic_cast<C *>(p);
	if (cPtr != NULL)
	{
		std::cout << "pointer p point to object C" << std::endl;
		return ;
	}

	std::cout << "pointer p point to unrelated object" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	&aRef = dynamic_cast<A &>(p);
		(void)aRef;
		std::cout << "reference p point to object A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B	&bRef = dynamic_cast<B &>(p);
			(void)bRef;
			std::cout << "reference p point to object B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C	&cRef = dynamic_cast<C &>(p);
				(void)cRef;
				std::cout << "reference p point to object C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "reference p point to unrelated object" << std::endl;
			}
		}

	}
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
	Base	&baseRef1 = *basePtr1;
	sleep(1);
	Base	*basePtr2 = generate();
	Base	&baseRef2 = *basePtr2;
	sleep(1);
	Base	*basePtr3 = generate();
	Base	&baseRef3 = *basePtr3;
	sleep(1);
	Base	*basePtr4 = new Base();
	Base	&baseRef4 = *basePtr4;

	identify(baseRef1);
	identify(baseRef2);
	identify(baseRef3);
	identify(baseRef4);

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
