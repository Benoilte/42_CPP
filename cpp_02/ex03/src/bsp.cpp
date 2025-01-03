# include "Point.hpp"

/*
	1. Check position relative to each edge

	2. Point is inside if all cross-products have the same sign

		BSP tree:

							   AB
							  /  \
							BC   null
						   /  \
						 CA   null
						/  \
		 Inside Triangle	null

	   										AB
	   									   /  \
	   									null   BC
	   										  /	 \
	   									  null	  CA
	   										  	 /	\
	   										 null	 Inside Triangle
*/

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed cross2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed cross3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return true;
	else
		return false;
}
