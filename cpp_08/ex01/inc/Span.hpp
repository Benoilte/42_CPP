#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <functional>

class Span
{
	private:

	
		// PRIVATE ATTRIBUTE //

		unsigned int		m_capacity;
		std::vector<int>	m_span;

		// STATIC CONST ATTRIBUTE

		static const unsigned int	mandatorySizeToFindSpan = 2;
		// static const unsigned int	firstIndex = 1;

		// PRIVATE MEMBER FUNCTION //

		bool	isSorted(void) const;

		// PRIVATE STATIC FUNCTION //

		static void	SpanIsToShort(unsigned int t_n);
		static int	generateOrderedNumber();
		static int	generateRandomNumber();

		// PRIVATE CONSTRUCTOR //

		Span();

	public:


		typedef std::vector<int>::const_iterator	spanConstIt;
		typedef std::vector<int>::iterator			spanIt;

		// CONSTRUCTOR //

		Span(unsigned int t_n);
		Span(const Span &t_src);

		// DESTRUCTOR //

		~Span();

		// OPERATOR OVERLOAD //

		Span	&operator=(const Span &t_rhs);

		// GETTER //

		const unsigned int		&getCapacity(void) const;
		const std::vector<int>	&getSpan(void) const;

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		void		addNumber(int t_n);
		long int	shortestSpan() const;
		long int	longestSpan() const;
		void		fillWithOrderedNumber();
		void		filWithRandomNumber();

};

std::ostream	&operator<<(std::ostream &t_out, Span const &t_rhs);

#endif
