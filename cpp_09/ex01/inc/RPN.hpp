#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>

class RPN
{
	public:

		RPN();
		RPN(const std::string &str);
		RPN(const RPN &other);
		~RPN();

		RPN	&operator=(const RPN &rhs);

		int	compute(void);

	private:

		const std::string m_rpnSequence;

};

std::ostream	&operator<<(std::ostream &out, RPN const &rhs);

#endif
