#include "Fixed.hpp"
#include <iostream>

void	testFromSubject(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}

void	testSimple(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( -2 );
	Fixed const e( 8 );

	a = Fixed( 1234.4321f );

	std::cout << a <<  " + " << b << " = " << a + b << std::endl; // 1244.43
	std::cout << a <<  " - " << b << " = " << a - b << std::endl; // 1224.43
	std::cout << e <<  " - " << b << " = " << e - b << std::endl; // -2
	std::cout << c <<  " * " << b << " = " << c * b << std::endl; // 424.219
	std::cout << c <<  " / " << b << " = " << c / b << std::endl; // 4.24219
	std::cout << d <<  " - " << e << " = " << d - e << std::endl; // -10
	std::cout << d <<  " * " << d << " = " << d * d << std::endl; // 4
	std::cout << d <<  " * " << b << " = " << d * b << std::endl; // -20
	std::cout << "Min between: " << b << " and " << c << ": " << Fixed::min( b, c ) << std::endl; // 10
	std::cout << "Max between: " << a << " and " << c << ": " << Fixed::max( a, c ) << std::endl; // 1234.43
	std::cout << "Max between: " << d << " and " << e << ": " << Fixed::max( d, e ) << std::endl; // 8
	std::cout << "Min between: " << d << " and " << e << ": " << Fixed::min( d, e ) << std::endl; // -2
	// std::cout << (Fixed::max( b, c ))++ << std::endl; // Fail compilation
}

int	main(void)
{
	std::cout << "Test from subject:" << std::endl;
	testFromSubject();
	std::cout << "\nTest simple:" << std::endl;
	testSimple();

	return 0;
}
