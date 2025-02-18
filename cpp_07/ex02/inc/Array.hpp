#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array
{
	private:
	
		// PRIVATE ATTRIBUTE //

		unsigned int	arraySize;
		T				*elements;

		// PRIVATE MEMBER FUNCTION //

		// NESTED CLASS EXCEPTION
		
		class outOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return "Error: Index out of bounds";
				}
		};

	public:

		// CONSTRUCTOR //

		Array<T>() : arraySize(0)
		{
			// DEFAULT CONSTRUCTOR
			elements = new T[arraySize];
		}

		Array<T>(unsigned int t_n) : arraySize(t_n)
		{
			// PARAMETRIZED CONSTRUCTOR
			elements = new T[arraySize];
		}

		Array<T>(const Array<T> &t_src)
		{
			// COPY CONSTRUCTOR
			elements = new T[t_src.size()];
			*this = t_src;

			return ;
		}

		// DESTRUCTOR //

		~Array<T>()
		{
			// DESTRUCTOR
			delete [] elements;
		}



		// OPERATOR OVERLOAD //

		Array	&operator=(const Array &t_rhs)
		{
			// OVERLOAD ASSIGNEMENT OPERATOR
			arraySize = t_rhs.size();
			delete [] elements;
			elements = new T[arraySize];
			for (unsigned int i = 0; i < arraySize; i++)
				elements[i] = t_rhs[i];

			return *this;
		}

		T	&operator[](const int &t_index)
		{
			if ((t_index < 0) || static_cast<unsigned int>(t_index) >= arraySize) 
				throw Array::outOfBoundsException();
			return elements[t_index];
		}

		T const	&operator[](const int &t_index) const
		{
			if ((t_index < 0) || static_cast<unsigned int>(t_index) >= arraySize)
				throw Array::outOfBoundsException();
			return elements[t_index];
		}

		// GETTER //
		unsigned int	size() const
		{
			return arraySize;
		}

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

		bool			empty() const
		{
			return ((arraySize == 0) ? true : false);
		}

};

template<typename T>
std::ostream	&operator<<(std::ostream &t_out, Array<T> const &t_rhs){
	for (unsigned int i = 0; i < t_rhs.size(); i++)
		t_out << i << ":\t" << t_rhs[i] << '\n';
	
	return t_out;
}

#endif
