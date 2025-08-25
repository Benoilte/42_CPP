#include "Input.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

Input::Input()
{
    //  DEFAULT
}

Input::Input(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		fillContainer(argv[i]);
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

const std::vector<int>	&Input::getVecInput() const { return vecInput; }
const std::deque<int>	&Input::getDeqInput() const { return deqInput; }

//  ============| SETTERS |=============

//  ============| METHODS |=============

void				Input::fillContainer(const std::string &str)
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
			if ((n < 0) || isDuplicates(n))
				throw std::runtime_error("Error");
			vecInput.push_back(n);
			deqInput.push_back(n);
		}
	}
}

bool				Input::isDuplicates(const int &n)
{
	for (std::vector<int>::iterator it = vecInput.begin() ; it != vecInput.end(); ++it)
		if (*it == n) return true;
	return false;
}
//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, Input const &rhs)
{
	for (std::vector<int>::const_iterator it = rhs.getVecInput().begin() ; it != rhs.getVecInput().end(); ++it)
		out << *it << ' ';
	return out;
	// for (std::deque<int>::const_iterator it = rhs.getDeqInput().begin() ; it != rhs.getDeqInput().end(); ++it)
	// 	out << *it << ' ';
	// return out;
}