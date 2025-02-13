#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private:
	
		// PRIVATE ATTRIBUTE //

		// PRIVATE MEMBER FUNCTION //

	public:

		// CONSTRUCTOR //

		Array<T>(){
			// DEFAULT CONSTRUCTOR
		}
		Array<T>(unsigned int t_n){
			// PARAMETRIZED CONSTRUCTOR
		}
		Array<T>(const Array<T> &t_src){
			// COPY CONSTRUCTOR
		}

		// DESTRUCTOR //

		~Array<T>(){
			// DESTRUCTOR
		}

		// OPERATOR OVERLOAD //

		Array	&operator=(const Array &t_rhs){
			// OVERLOAD ASSIGNEMENT OPERATOR
		}

		// GETTER //

		// SETTER //

		// PUBLIC MEMBER FUNCTION //

};

template<typename T>
std::ostream	&operator<<(std::ostream &t_out, Array<T> const &t_rhs){
	t_out << "print Array element";
	return t_out;
}

#endif
