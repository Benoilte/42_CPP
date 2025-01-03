#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    /*Constructor*/
	std::cout << "Point Default Constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY())
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point::Point(float const a, float const b) : _x(a), _y(b)
{
	std::cout << "Point Parametrized Constructor called" << std::endl;
}

Point::~Point()
{
	/*Destructor*/
}

Point& Point::operator=(const Point &rhs)
{
	(void)rhs;

	return *this;
}

Fixed const Point::getX(void) const
{
	return _x;
}

Fixed const Point::getY(void) const
{
	return _y;
}

std::ostream& operator<<(std::ostream &out, Point const &rhs)
{
	out << rhs.getX() << " ; " << rhs.getY();
	return out;
}
