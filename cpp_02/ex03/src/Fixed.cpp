#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;

	return ;
}

Fixed::Fixed(int const n) : _rawBits(n << _fractionalBits)
{
}

Fixed::Fixed(float const f)
{
	_rawBits = (f * float(1 << _fractionalBits) + (f >= 0 ? 0.5 : -0.5));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();

	return *this;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++()
{
	*this = Fixed(this->toFloat() + 0.00390625f);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;

	*this = Fixed(this->toFloat() + 0.00390625f);
	return tmp;
}

Fixed Fixed::operator--()
{
	*this = Fixed(this->toFloat() - 0.00390625f);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;

	*this = Fixed(this->toFloat() - 0.00390625f);
	return tmp;
}

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return float(_rawBits) / float(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;	
	return b;
}

Fixed const& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream& operator<<(std::ostream &out, Fixed const &rhs)
{
	if (rhs.toFloat() - rhs.toInt() == 0)
		out << rhs.toInt();
	else
		out << rhs.toFloat();

	return out;
}
