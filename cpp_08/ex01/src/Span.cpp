#include "Span.hpp"

Span::Span() : m_capacity(0)
{
    /*Constructor*/
}

Span::Span(const Span &t_src)
{
	*this = t_src;

	return ;
}

Span::Span(unsigned int t_n) : m_capacity(t_n)
{
	std::srand(time(NULL));
	m_span.reserve(m_capacity);
	/*Paramtrized Constructor*/
}

Span::~Span()
{
	/*Destructor*/
}

Span& Span::operator=(const Span &t_rhs)
{
	if (this != &t_rhs)
	{
		this->m_capacity = t_rhs.getCapacity();
		this->m_span = t_rhs.getSpan();
	}
	
	return *this;
}

const unsigned int &Span::getCapacity(void) const
{
	return m_capacity;
}

const std::vector<int>	&Span::getSpan(void) const
{
	return m_span;
}

void Span::addNumber(int t_n)
{
	if (m_span.size() < m_capacity)
		m_span.push_back(t_n); 
	else
	{
		std::cerr << "Error: " << t_n << " Should not be added: ";
		throw std::runtime_error("Your span reached its maximum capacity");
	}
}

long int Span::shortestSpan() const
{
	if (m_span.size() < mandatorySizeToFindSpan)
		SpanIsToShort(m_span.size());

	std::vector<int>	spCopy(m_span);
	long int			shortestSpan = std::numeric_limits<long int>::max();

	if (!isSorted())
		std::sort(spCopy.begin(), spCopy.end());
	for (spanIt it = spCopy.begin(); it != (spCopy.end() - 1); it++)
	{
		long int diff = static_cast<long int>(*(it + 1)) - static_cast<long int>(*it);
		if (diff < shortestSpan)
			shortestSpan = diff;
	}
	return shortestSpan;
}

long int Span::longestSpan() const
{
	if (m_span.size() < mandatorySizeToFindSpan)
		SpanIsToShort(m_span.size());

	long int max = static_cast<long int>(*std::max_element(m_span.begin(), m_span.end()));
	long int min = static_cast<long int>(*std::min_element(m_span.begin(), m_span.end()));
	return (max - min);
}

void	Span::fillWithOrderedNumber()
{
	m_span.resize(m_capacity);
	std::generate(m_span.begin(), m_span.end(), &Span::generateOrderedNumber);
}

void	Span::filWithRandomNumber()
{
	m_span.resize(m_capacity);
	std::generate(m_span.begin(), m_span.end(), &Span::generateRandomNumber);
}

std::ostream& operator<<(std::ostream &t_out, Span const &t_rhs)
{
	for (Span::spanConstIt it = t_rhs.getSpan().begin(); it != t_rhs.getSpan().end(); it++)
		t_out << *it << ' ';
	return t_out; 
}

bool Span::isSorted(void) const
{
	for (spanConstIt it = m_span.begin(); it != (m_span.end() - 1); it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

int Span::generateOrderedNumber()
{
	static unsigned int		index;

	index %= std::numeric_limits<int>::max();
	return ++index;
}

int Span::generateRandomNumber()
{
	return (std::rand() % std::numeric_limits<int>::max());
}

void Span::SpanIsToShort(unsigned int t_n)
{
	std::cerr << "Error: Span has a size of: " << t_n << ": ";
	throw std::runtime_error("Your span is too short");
}
