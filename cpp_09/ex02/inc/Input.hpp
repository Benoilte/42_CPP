#ifndef INPUT_HPP
#define INPUT_HPP

# include <iostream>
# include <sstream>
# include <vector>
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

		const std::vector<int>	&getInput(void) const;
		size_t					getInputSize(void) const;
	
	private:

		void				fillInput(const std::string &str);
		bool				isDuplicate(const int &n);

		std::vector<int>	m_input;

};

std::ostream	&operator<<(std::ostream &out, Input const &rhs);

#endif
