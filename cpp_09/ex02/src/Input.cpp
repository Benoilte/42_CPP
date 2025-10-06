#include "Input.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

Input::Input()
{
    //  DEFAULT
}

Input::Input(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		fillInput(argv[i]);
}

Input::Input(const Input &other)
{
	*this = other;
}

Input::~Input()
{
	//  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======

Input& Input::operator=(const Input &rhs)
{
	if (this != &rhs)
	{
		;
	}

	return *this;
}

//  ============| GETTERS |=============

const std::vector<int>	&Input::getInput() const { return m_input; }
size_t	Input::getInputSize() const { return m_input.size(); }

//  ============| SETTERS |=============

//  ============| METHODS |=============

void				Input::fillInput(const std::string &str)
{
	std::stringstream	ss(str);
	int					n;

	while (!ss.eof())
	{
		ss >> n;
		if (ss.fail())
			throw std::runtime_error("Error");
		else
		{
			if ((n < 0))
				throw std::runtime_error("Error");
			m_input.push_back(n);
		}
	}
}

bool				Input::isDuplicate(const int &n)
{
	for (std::vector<int>::iterator it = m_input.begin() ; it != m_input.end(); ++it)
		if (*it == n) return true;
	return false;
}
//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, Input const &rhs)
{
	for (std::vector<int>::const_iterator it = rhs.getInput().begin() ; it != rhs.getInput().end(); ++it)
		out << *it << ' ';
	return out;
}