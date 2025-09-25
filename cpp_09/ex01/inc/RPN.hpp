#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>

class RPN
{
	
	
	public:
	
		RPN();
		RPN(const RPN &other);
		~RPN();
		
		RPN	&operator=(const RPN &rhs);
	
	private:

};

std::ostream	&operator<<(std::ostream &out, RPN const &rhs);

#endif
