#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

/*
	typedef typename _Sequence::value_type                value_type;
	typedef typename _Sequence::reference                 reference;
	typedef typename _Sequence::const_reference           const_reference;
	typedef typename _Sequence::size_type                 size_type;
	typedef          _Sequence                            container_type;
*/

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

		// MutantStack(int const t_n)
		// {

		// };

		MutantStack<T, U>(const MutantStack &t_src) : std::stack<T, U>(t_src)
		{
			// *this = t_src;

			// return ;
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

		// GETTER //

		// SETTER //

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
	
		// PRIVATE ATTRIBUTE //

		// PRIVATE MEMBER FUNCTION //
};

// std::ostream	&operator<<(std::ostream &t_out, MutantStack const &t_rhs);

#endif
