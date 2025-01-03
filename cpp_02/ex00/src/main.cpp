#include "Fixed.hpp"
#include <iostream>

void	testFromSubject(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

void	testSimple(void)
{
	Fixed a;

	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(-42);
	std::cout << a.getRawBits() << std::endl;
}

int	main(void)
{
	std::cout << "Test from subject: " << std::endl;
	testFromSubject();
	std::cout << "\nTest simple: " << std::endl;
	testSimple();
	return 0;
}

