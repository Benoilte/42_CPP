#include "Fixed.hpp"
#include <iostream>

void	testFromSubject(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	testSimple(void)
{
	Fixed const a( -42 );
	Fixed const b( -42.42f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
}

int	main(void)
{
	std::cout << "Test from subject: " << std::endl;
	testFromSubject();
	std::cout << "\nTest simple: " << std::endl;
	testSimple();
	return 0;
}
