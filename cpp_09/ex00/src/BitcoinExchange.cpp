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
	if (m_dataBaseFile.is_open())
		m_dataBaseFile.close();

	if (m_inputFile.is_open())
		m_inputFile.close();
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

void	BitcoinExchange::init(void)
{
	m_dataBaseFile.open("data.csv");
	if (!m_dataBaseFile.is_open())
		throw BtcException("failed to open data base file");

	m_inputFile.open(m_inputStr.c_str());
	if (!m_inputFile.is_open())
		throw BtcException("failed to open input file");

	initDataBase();
}

void	BitcoinExchange::initDataBase(void)
{
	std::string			line;
	std::string			date;
	float				exchangeRate;

	std::getline(m_dataBaseFile, line);
	if (line != "date,exchange_rate")
		throw BtcException("Database title does not match: date,exchange_rate");
	std::getline(m_dataBaseFile, line);
	while (!m_dataBaseFile.eof())
	{
		std::cout << line.substr(0, line.find(',')) << std::endl;
		parseDate(line, date);
		parseExchangeRate(line, exchangeRate);
		std::getline(m_dataBaseFile, line);
	}
}

void	BitcoinExchange::parseDate(std::string &line, std::string &date)
{
	date = line.substr(0, line.find(','));
}

void	BitcoinExchange::parseExchangeRate(std::string &line, float &exchangeRate)
{
	std::stringstream ss;

	ss << line.substr(line.find(',') + 1);
	ss >> exchangeRate;
	if (!ss.good())
}

void	BitcoinExchange::display(void)
{

}

//  ============| CUSTOM EXCEPTION |=============

BitcoinExchange::BtcException::BtcException() throw()
: m_message("")
{
	// Custom Exception default Constructor
}

BitcoinExchange::BtcException::BtcException(const char* msg) throw()
: m_message(msg)
{
	// Custom Exception Constructor
}

BitcoinExchange::BtcException::~BtcException() throw()
{
	// Custom Exception Constructor
}

const char	*BitcoinExchange::BtcException::what() const throw()
{
	return m_message.c_str();
}

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream& operator<<(std::ostream &out, BitcoinExchange const &rhs)
{
	(void)rhs;
	return out;
}
