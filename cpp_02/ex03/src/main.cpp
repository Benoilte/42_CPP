#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a;
	Point b(3, 2.30000);
	Point c;

	c = b;
	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;
	return 0;
}
