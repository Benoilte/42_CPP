#include "bsp.hpp"

void	displayTest(Point const a, Point const b, Point const c)
{
	std::cout << "Triangle with vertices: a(" << a << ") b(" << b << ") c(" << c << ")" << std::endl;
}

void	displayMsgPointIn(Point const p)
{
	std::cout << GREEN << "point (" << p << ") is inside of the triangle" << RESET << std::endl;
}

void	displayMsgPointOut(Point const p)
{
	std::cout << RED << "point (" << p << ") is outside of the triangle" << RESET << std::endl;
}

int	main(void)
{
	Point a1(1, 1), b1(5, 1), c1(3, 4), p1(3, 2), p2(6, 2), p3(3, 4);
	displayTest(a1, b1, c1);
	bsp(a1, b1, c1, p1) ? displayMsgPointIn(p1) : displayMsgPointOut(p1); // IN
	bsp(a1, b1, c1, p2) ? displayMsgPointIn(p2) : displayMsgPointOut(p2); // OUT
	bsp(a1, b1, c1, p3) ? displayMsgPointIn(p3) : displayMsgPointOut(p3); // OUT (on vertices c1)

	std::cout << std::endl;

	Point a2(0, 0), b2(4, 0), c2(2, 3), p4(2, 1), p5(2, 4), p6(3, 1.5);
	displayTest(a2, b2, c2);
	bsp(a2, b2, c2, p4) ? displayMsgPointIn(p4) : displayMsgPointOut(p4); // IN
	bsp(a2, b2, c2, p5) ? displayMsgPointIn(p5) : displayMsgPointOut(p5); // OUT
	bsp(a2, b2, c2, p6) ? displayMsgPointIn(p6) : displayMsgPointOut(p6); // OUT (on edge BC)

	std::cout << std::endl;

	Point a3(-1, -1), b3(3, -1), c3(1, 2), p7(1.5, 0.5), p8(4, -2), p9(2, 0.5);
	displayTest(a3, b3, c3);
	bsp(a3, b3, c3, p7) ? displayMsgPointIn(p7) : displayMsgPointOut(p7); // IN
	bsp(a3, b3, c3, p8) ? displayMsgPointIn(p8) : displayMsgPointOut(p8); // OUT
	bsp(a3, b3, c3, p9) ? displayMsgPointIn(p9) : displayMsgPointOut(p9); // OUT (on edge BC)

	std::cout << std::endl;
	
	Point a4(2, 1), b4(6, 1), c4(4, 5), p10(4, 2.5), p11(2, 6), p12(3, 3);
	displayTest(a4, b4, c4);
	bsp(a4, b4, c4, p10) ? displayMsgPointIn(p10) : displayMsgPointOut(p10); // IN
	bsp(a4, b4, c4, p11) ? displayMsgPointIn(p11) : displayMsgPointOut(p11); // OUT
	bsp(a4, b4, c4, p12) ? displayMsgPointIn(p12) : displayMsgPointOut(p12); // OUT (on edge AC)

	return 0;
}
