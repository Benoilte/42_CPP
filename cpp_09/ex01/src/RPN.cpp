#include "RPN.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

RPN::RPN()
: m_rpnSequence(""), m_succeed(false), m_result(0)
{
    //  DEFAULT
}

RPN::RPN(const std::string &input)
: m_rpnSequence(input), m_succeed(false), m_result(0)
{
    //  DEFAULT
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
	//  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======

RPN& RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		;
	}

	return *this;
}

//  ============| GETTERS |=============

bool	RPN::getSucceed(void) const { return m_succeed; }
int		RPN::getResult(void) const { return m_result; }
//  ============| SETTERS |=============

//  ============| METHODS |=============

void	RPN::compute(void)
{
	try
	{
		for (size_t i = 0; i < m_rpnSequence.size(); i++)
		{
			if (std::isdigit(m_rpnSequence[i]))
				m_stack.push_back(m_rpnSequence[i] - '0');
			else if (std::isspace(m_rpnSequence[i]))
				continue;
			else
				computeStack(m_rpnSequence[i]);
		}
		if (m_stack.size() == 1)
		{
			m_succeed = true;
			m_result = m_stack.back();
		}
	}
	catch(const RPN::OperationFailed& e)
	{
		;
	}
	catch(const std::exception& e)
	{
		;
	}
}

void	RPN::computeStack(const char &token)
{
	if (m_stack.size() < 2)
		throw OperationFailed();

	int	rightOperand = m_stack.back();
	m_stack.pop_back();
	int leftOperand = m_stack.back();
	m_stack.pop_back();

	if ((token == '+') && !addOverflow(leftOperand, rightOperand))
		m_stack.push_back(leftOperand + rightOperand);
	else if ((token == '-') && !subOverflow(leftOperand, rightOperand))
		m_stack.push_back(leftOperand - rightOperand);
	else if ((token == '*') && !multOverflow(leftOperand, rightOperand))
		m_stack.push_back(leftOperand * rightOperand);
	else if ((token == '/') && !divOverflow(leftOperand, rightOperand))
		m_stack.push_back(leftOperand / rightOperand);
	else
		throw OperationFailed();
}

bool RPN::addOverflow(int lhs, int rhs)
{
	if (lhs >= 0)
		return (rhs > (std::numeric_limits<int>::max() - lhs));
	else
    	return (rhs < (std::numeric_limits<int>::min() - lhs));
}

bool RPN::subOverflow(int lhs, int rhs)
{
    if (rhs <= 0)
        return (lhs > std::numeric_limits<int>::max() + rhs);
    else
        return (lhs < std::numeric_limits<int>::min() + rhs);
}

bool RPN::multOverflow(int lhs, int rhs)
{
	if (lhs == 0 || rhs == 0) return false;

    if (lhs == std::numeric_limits<int>::min())
        return ((rhs != 0) && (rhs != 1));
    if (rhs == std::numeric_limits<int>::min())
        return ((lhs != 0) && (lhs != 1));

    return std::abs(lhs) > std::numeric_limits<int>::max() / std::abs(rhs);
}

bool RPN::divOverflow(int lhs, int rhs)
{
    return (rhs == 0) || ((lhs == std::numeric_limits<int>::min()) && (rhs == -1));
}

const char	*RPN::OperationFailed::what() const throw()
{
	return "";
}
//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, RPN const &rhs)
{
	if (rhs.getSucceed())
		out << rhs.getResult();
	else
		out << "ERROR";

	return out;
}
