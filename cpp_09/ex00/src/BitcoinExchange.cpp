#include "BitcoinExchange.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========

BitcoinExchange::BitcoinExchange()
{
    //  DEFAULT m_input.open(configFile.c_str(), std::ios::in);
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

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, BitcoinExchange const &rhs)
{
	(void)rhs;
	return out;
}
