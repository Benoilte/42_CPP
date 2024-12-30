#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(int const n);
		Fixed(float const f);
		Fixed(const Fixed &src);
		~Fixed();

		Fixed		&operator=(const Fixed &rhs);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

		float		toFloat( void ) const;
		int			toInt( void ) const;

	private:
	
		int					_rawBits;
		static const int	_fractionalBits;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
