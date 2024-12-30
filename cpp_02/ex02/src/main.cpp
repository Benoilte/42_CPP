#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed d;
	Fixed const e( 10 );
	Fixed const f( 42.42f );

	d = Fixed( 1234.4321f );

	std::cout << d <<  " + " << e << " = " << d + e << std::endl;
	std::cout << d <<  " - " << e << " = " << d - e << std::endl;
	std::cout << f <<  " * " << e << " = " << f * e << std::endl;
	std::cout << f <<  " / " << e << " = " << f / e << std::endl;
	std::cout << Fixed::min( e, f ) << std::endl;
	std::cout << Fixed::max( d, f ) << std::endl;
	std::cout << ++(Fixed::max( d, d )) << std::endl;
	// std::cout << ++(Fixed::max( e, f )) << std::endl;

	std::cout << "\nTest from subject : \n" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
