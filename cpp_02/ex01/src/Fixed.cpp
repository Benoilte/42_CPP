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

Fixed::Fixed(int const n) : _rawBits(n)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f)
{
	(void)f;
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
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (1.0);
}

int Fixed::toInt(void) const
{
	return 1;
}

std::ostream& operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.getRawBits();
	return out; 
}