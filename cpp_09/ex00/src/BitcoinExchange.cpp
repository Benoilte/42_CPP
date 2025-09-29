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
	m_dataBaseFile.open("errorData.csv");
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
		throw BtcException("Database title invalid format, Expected: date,exchange_rate");
	std::getline(m_dataBaseFile, line);
	while (!line.empty() || !m_dataBaseFile.eof())
	{
		try
		{
			parseDate(line, date);
			parseExchangeRate(line, exchangeRate);
			m_dateRateMap.insert(make_pair(date, exchangeRate));
		}
		catch(const BitcoinExchange::BtcException& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		line.clear();
		std::getline(m_dataBaseFile, line);
	}
	if (m_dateRateMap.empty())\
		throw BtcException("Database is empty after initialisation");
	for (std::map<std::string, float>::iterator it = m_dateRateMap.begin(); it != m_dateRateMap.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
}

// 2009-02-07
void	BitcoinExchange::parseDate(std::string &line, std::string &date)
{
	date = line.substr(0, line.find(','));

	if (date.size() != 10)
		throw BtcException("Date size invalid, Expected: yyyy-mm-dd");
	for (int i = 0; i < 10; i++)
	{
		if ((i == 4) || (i == 7))
		{
			if (date[i] != '-')
				throw BtcException("Invalid separator (" + date + "). Expected: yyyy-mm-dd");
		}
		else if (!std::isdigit(date[i]))
			throw BtcException("Invalid date format (" + date + "). Date should contain only digit as expected: yyyy-mm-dd");
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	validYear(date, year);
	validMonth(date, month);
	validDay(date, year, month, day);

	if (date > m_todayDate)
		throw BtcException("Invalid date format (" + date + ") the provided date is later than today. Expected a date earlier or equal than today: " + m_todayDate);
}

void	BitcoinExchange::validYear(const std::string &date, const int &year)
{
	std::string invalidYearMsg = "Invalid year format (" + date + "). Expected between: 2000 - " + m_todayDate.substr(0, 4);

	if (year < 2000 || year > std::atoi(m_todayDate.substr(0, 4).c_str()))
		throw BtcException(invalidYearMsg);
}

void	BitcoinExchange::validMonth(const std::string &date, const int &month)
{
	if ((month < 1) || (month > 12))
		throw BtcException("Invalid month format (" + date + "). Expected between: 01 - 12");
}

void	BitcoinExchange::validDay(const std::string &date, const int &year, const int &month, const int &day)
{
	int maxDay = 31;

	if (month == 2)
	{
		if (isLeapYear(year))
			maxDay = 29;
		else
			maxDay = 28;  
	}
	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		maxDay = 30;

	if ((day < 1) || (day > maxDay))
		throw BtcException("Invalid day format (" + date + "). Expected between: 01 - " + convertToString(maxDay));
}

bool	BitcoinExchange::isLeapYear(const int &year)
{
	if ((year % 400) == 0)
			return true;
	else if ((year % 100) == 0)
			return false;
	else if ((year % 4) == 0)
			return true;
	else
			return false;
}

void	BitcoinExchange::parseExchangeRate(std::string &line, float &exchangeRate)
{
	std::stringstream	ss;
	std::string			exchangeRateStr = line.substr(line.find(',') + 1);
	size_t				countPoint = 0;

	for (size_t i = 0; i < exchangeRateStr.size(); i++)
	{
		if (exchangeRateStr[i] == '.')
			countPoint++;
		else if (!std::isdigit(exchangeRateStr[i]))
			throw BtcException("Exchange rate invalid format, expected only digit or dot");
	}
	if (countPoint > 1)
		throw BtcException("Exchange rate invalid format, too many dot");

	ss << exchangeRateStr;
	ss >> exchangeRate;
	if (ss.fail())
		throw BtcException("Exchange rate invalid format");
}

const std::string		BitcoinExchange::convertToString(const int &n)
{
	std::stringstream ss;

	ss << n;
	return ss.str();
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

BitcoinExchange::BtcException::BtcException(std::string msg) throw()
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
