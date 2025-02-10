#include "utils.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	int a = 2;
	int b = 3;

	std::cout << CYAN << "Test template with int '2' and '3'" << RESET << std::endl;
	std::cout << YELLOW << "Test swap function" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << YELLOW << "\nTest min / max function" << RESET << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << CYAN << "\nTest template with string 'chaine1' and 'chaine2'" << RESET << std::endl;
	std::cout << YELLOW << "Test swap function" << RESET << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << YELLOW << "\nTest min / max function" << RESET << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	float e = 4.2f;
	float f = -2.1f;

	std::cout << CYAN << "\nTest template with float '4.2' and '-2.1'" << RESET << std::endl;
	std::cout << YELLOW << "Test swap function" << RESET << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;

	std::cout << YELLOW << "\nTest min / max function" << RESET << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	double g = 8.4;
	double h = 16.8;

	std::cout << CYAN << "\nTest template with double '8.4' and '16.8'" << RESET << std::endl;
	std::cout << YELLOW << "Test swap function" << RESET << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;

	std::cout << YELLOW << "\nTest min / max function" << RESET << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;

	const int i = 4;
	const int j = 8;

	std::cout << CYAN << "\nTest template with const int '4' and '8'" << RESET << std::endl;
	// std::cout << YELLOW << "Test swap function" << RESET << std::endl;
	// std::cout << "i = " << i << ", j = " << j << std::endl;
	// ::swap(i, j);
	// std::cout << "i = " << i << ", j = " << j << std::endl;

	std::cout << YELLOW << "\nTest min / max function" << RESET << std::endl;
	std::cout << "min( i, j ) = " << ::min( i, j ) << std::endl;
	std::cout << "max( i, j ) = " << ::max( i, j ) << std::endl;

	return 0;
}

