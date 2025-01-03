#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define RESET	"\033[0m"

void	displayMsgPointIn(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << GREEN << "point (" << p << ") is inside of the triangle (" << a << ") (" << b << ") (" << c << ")" << RESET << std::endl;
}

void	displayMsgPointOut(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << RED << "point (" << p << ") is outside of the triangle (" << a << ") (" << b << ") (" << c << ")" << RESET << std::endl;
}

int	main(void)
{
	Point a1(1, 1), b1(5, 1), c1(3, 4), p1(3, 2), p2(3, 4), p3(6, 2);

	bsp(a1, b1, c1, p1) ? displayMsgPointIn(a1, b1, c1, p1) : displayMsgPointOut(a1, b1, c1, p1); // IN
	bsp(a1, b1, c1, p2) ? displayMsgPointIn(a1, b1, c1, p2) : displayMsgPointOut(a1, b1, c1, p2); // OUT
	bsp(a1, b1, c1, p3) ? displayMsgPointIn(a1, b1, c1, p3) : displayMsgPointOut(a1, b1, c1, p3); // OUT

	std::cout << std::endl;

	Point a2(0, 0), b2(4, 0), c2(2, 3), p4(2, 1), p5(2, 4), p6(2, 0);
	bsp(a2, b2, c2, p4) ? displayMsgPointIn(a2, b2, c2, p4) : displayMsgPointOut(a2, b2, c2, p4); // IN
	bsp(a2, b2, c2, p5) ? displayMsgPointIn(a2, b2, c2, p5) : displayMsgPointOut(a2, b2, c2, p5); // OUT
	bsp(a2, b2, c2, p6) ? displayMsgPointIn(a2, b2, c2, p6) : displayMsgPointOut(a2, b2, c2, p6); // OUT

	std::cout << std::endl;

	Point a3(-1, -1), b3(3, -1), c3(1, 2), p7(1.5, 0.5), p8(4, -2), p9(1, -1);
	bsp(a3, b3, c3, p7) ? displayMsgPointIn(a3, b3, c3, p7) : displayMsgPointOut(a3, b3, c3, p7); // IN
	bsp(a3, b3, c3, p8) ? displayMsgPointIn(a3, b3, c3, p8) : displayMsgPointOut(a3, b3, c3, p8); // OUT
	bsp(a3, b3, c3, p9) ? displayMsgPointIn(a3, b3, c3, p9) : displayMsgPointOut(a3, b3, c3, p9); // OUT

	std::cout << std::endl;
	
	Point a4(2, 1), b4(6, 1), c4(4, 5), p10(4, 2.5), p11(2, 6), p12(4, 1);
	bsp(a4, b4, c4, p10) ? displayMsgPointIn(a4, b4, c4, p10) : displayMsgPointOut(a4, b4, c4, p10); // IN
	bsp(a4, b4, c4, p11) ? displayMsgPointIn(a4, b4, c4, p11) : displayMsgPointOut(a4, b4, c4, p11); // OUT
	bsp(a4, b4, c4, p12) ? displayMsgPointIn(a4, b4, c4, p12) : displayMsgPointOut(a4, b4, c4, p12); // OUT

	return 0;
}
