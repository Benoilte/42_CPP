#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::Fixed(int const n) : _rawBits(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = (f * float(1 << _fractionalBits) + (f >= 0 ? 0.5 : -0.5));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();

	return *this;
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

std::ostream& operator<<(std::ostream &out, Fixed const &rhs)
{
	if (rhs.toFloat() - rhs.toInt() == 0)
		out << rhs.toInt();
	else
		out << rhs.toFloat();

	return out;
}
