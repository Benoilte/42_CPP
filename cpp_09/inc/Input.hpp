#ifndef INPUT_HPP
#define INPUT_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <string>
# include <exception>

class Input
{
	
	
	public:
	
		Input();
		Input(int argc, char **argv);
		Input(const Input &other);
		~Input();
		
		Input	&operator=(const Input &rhs);

		const std::vector<int>	&getVecInput(void) const;
		const std::deque<int>	&getDeqInput(void) const;
	
	private:

		void				fillContainer(const std::string &str);
		bool				isDuplicates(const int &n);

		std::vector<int>	vecInput;
		std::deque<int>		deqInput;

};

std::ostream	&operator<<(std::ostream &out, Input const &rhs);

#endif
