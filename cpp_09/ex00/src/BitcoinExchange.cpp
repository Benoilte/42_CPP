#include "BitcoinExchange.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

BitcoinExchange::BitcoinExchange()
: m_inputStr("")
{
	char today[11];
	today[10] = '\0';

	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	strftime(today, 50, "%Y-%m-%d", &datetime);
	m_todayDate  = today;	
}

BitcoinExchange::BitcoinExchange(const std::string &input)
: m_inputStr(input)
{
	char today[11];
	today[10] = '\0';

	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	strftime(today, 50, "%Y-%m-%d", &datetime);
	m_todayDate  = today;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
	//  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		;
	}

	return *this;
}

//  ============| GETTERS |=============

//  ============| SETTERS |=============

//  ============| METHODS |=============

//  ============| CUSTOM EXCEPTION |=============

BitcoinExchange::BtcException::BtcException() throw()
: message("")
{
	// Custom Exception default Constructor
}

BitcoinExchange::BtcException::BtcException(const char* msg) throw()
: message(msg)
{
	// Custom Exception Constructor
}

BitcoinExchange::BtcException::~BtcException() throw()
{
	// Custom Exception Constructor
}

const char	*BitcoinExchange::BtcException::what() const throw()
{
	return message.c_str();
}

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, BitcoinExchange const &rhs)
{
	(void)rhs;
	return out;
}
