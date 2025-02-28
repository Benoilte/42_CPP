#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

template< typename T , typename U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
	public:

		typedef typename U::iterator iterator;
		typedef typename U::const_iterator const_iterator;
		typedef typename U::reverse_iterator reverse_iterator;
		typedef typename U::const_reverse_iterator const_reverse_iterator;

		// CONSTRUCTOR //

		MutantStack<T, U>() : std::stack<T, U>()
		{
			/*Default Constructor*/
		};

		MutantStack<T, U>(const MutantStack &t_src) : std::stack<T, U>(t_src)
		{

		};

		// DESTRUCTOR //

		~MutantStack<T, U>()
		{
			/*Destructor*/
		};

		// OPERATOR OVERLOAD //

		MutantStack	&operator=(const MutantStack &t_rhs)
		{
			if (this != &t_rhs)
				std::stack<T, U>::operator=(t_rhs);
	
			return *this;
		};

		// PUBLIC MEMBER FUNCTION //

		iterator		begin() { return this->c.begin(); };
		iterator		end() { return this->c.end(); };
		const_iterator	begin() const { return this->c.begin(); };
		const_iterator	end() const { return this->c.end(); };

		reverse_iterator		rbegin() { return this->c.rbegin(); };
		reverse_iterator		rend() { return this->c.rend(); };
		const_reverse_iterator	rbegin() const { return this->c.rbegin(); };
		const_reverse_iterator	rend() const { return this->c.rend(); };

	private:

};

#endif
