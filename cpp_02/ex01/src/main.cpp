#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	// test given by the subject
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;

	// personnal test
	b.setRawBits(42);
	std::cout << b.getRawBits() << std::endl;
	return 0;
}

