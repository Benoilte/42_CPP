#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

// Working range from -8388608 to 8388607

class Fixed
{
	public:

		Fixed();
		Fixed(int const n);
		Fixed(float const f);
		Fixed(const Fixed &src);
		~Fixed();

		Fixed		&operator=(const Fixed &rhs);

		bool		operator<(const Fixed &rhs) const;
		bool		operator<=(const Fixed &rhs) const;
		bool		operator>(const Fixed &rhs) const;
		bool		operator>=(const Fixed &rhs) const;
		bool		operator==(const Fixed &rhs) const;
		bool		operator!=(const Fixed &rhs) const;

		Fixed		operator+(const Fixed &rhs) const;
		Fixed		operator-(const Fixed &rhs) const;
		Fixed		operator*(const Fixed &rhs) const;
		Fixed		operator/(const Fixed &rhs) const;

		Fixed		operator++();
		Fixed		operator++(int);
		Fixed		operator--();
		Fixed		operator--(int);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

		float		toFloat( void ) const;
		int			toInt( void ) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(const Fixed &a, const Fixed &b);

	private:
	
		int					_rawBits;
		static const int	_fractionalBits;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
