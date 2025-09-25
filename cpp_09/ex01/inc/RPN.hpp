#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <limits>
# include <list>

class RPN
{
	public:

		RPN();
		RPN(const std::string &input);
		RPN(const RPN &other);
		~RPN();

		RPN	&operator=(const RPN &rhs);

		bool	getSucceed(void) const;
		int		getResult(void) const;
		void	compute(void);

	private:

		class OperationFailed : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		void	computeStack(const char &token);
		bool	addOverflow(int lhs, int rhs);
		bool	subOverflow(int lhs, int rhs);
		bool	multOverflow(int lhs, int rhs);
		bool	divOverflow(int lhs, int rhs);

		const std::string	m_rpnSequence;
		bool				m_succeed;
		int					m_result;
		std::list<int>		m_stack;

};

std::ostream	&operator<<(std::ostream &out, RPN const &rhs);

#endif
