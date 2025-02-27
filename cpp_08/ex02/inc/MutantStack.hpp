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

		typedef typename U::value_type	value_type;
		typedef typename U::reference	reference;
		typedef typename U::const_reference	const_reference;

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

		

		// NESTED ITERATOR CLASS

		class Iterator : public std::iterator<std::forward_iterator_tag, T>
		{
			public:
				
				Iterator() 
				{
					/*Default Constructor*/
				};

				// Iterator(int const t_n)
				// {

				// };

				Iterator(const Iterator &t_src)
				{
					*this = t_src;

					return ;
				};

				// DESTRUCTOR //

				~Iterator()
				{
					/*Destructor*/
				};

				// OPERATOR OVERLOAD //

				Iterator	&operator=(const Iterator &t_rhs)
				{
					if (this != &t_rhs)
						std::iterator<std::forward_iterator_tag, T>::operator=(t_rhs);
			
					return *this;
				};
		};

		typedef Iterator  iterator;


		// PUBLIC MEMBER FUNCTION //

		// void push(const value_type& val) 
		// { 
		// 	// std::cout << "Yolooo " << val << std::endl;
		// 	// c.push_back(val);
		// 	this->c.push_back(val);
		// 	if (this->size() == 1)
		// 		head = this->top();
		// }

		// T &getHead(void)
		// {
		// 	T	*head = NULL;

		// 	if (!this->empty())
		// 		head = (&this->top()) - ((this->size() - 1) * sizeof(U));
		// 	return *head;
		// }

	private:
	
		// PRIVATE ATTRIBUTE //

		// reference	*head;

		// PRIVATE MEMBER FUNCTION //
};

// std::ostream	&operator<<(std::ostream &t_out, MutantStack const &t_rhs);

#endif
