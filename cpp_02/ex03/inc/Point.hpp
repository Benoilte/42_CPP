#ifndef POINT_HPP
#define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:

		Point();
		Point(float const a, float const b);
		Point(const Point &src);
		~Point();

		Point	&operator=(const Point &rhs);

		Fixed const		getX(void) const;
		Fixed const		getY(void) const;

	private:

		Fixed const	_x;
		Fixed const	_y;
};

std::ostream	&operator<<(std::ostream &out, Point const &rhs);

#endif
