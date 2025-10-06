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
		this->m_todayDate = rhs.m_todayDate;
		this->m_inputStr = rhs.m_inputStr;
		this->m_dateRateMap = rhs.m_dateRateMap;
	}

	return *this;
}

//  ============| GETTERS |=============

//  ============| SETTERS |=============

//  ============| METHODS |=============

void	BitcoinExchange::init(void)
{
	m_dataBaseFile.open("csvFile/data.csv");
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
			parseDate(line, date, ",");
			parseValue(line, exchangeRate, ",");
			if (exchangeRate > 100000)
				throw BtcException("Exchange rate too large a number");
			m_dateRateMap.insert(make_pair(date, exchangeRate));
		}
		catch(const BitcoinExchange::BtcException& e)
		{
			std::cerr << "DB - Error: " << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "DB - Error: " << e.what() << std::endl;
		}
		line.clear();
		std::getline(m_dataBaseFile, line);
	}
	if (m_dateRateMap.empty())\
		throw BtcException("Database is empty after initialisation");
}

void	BitcoinExchange::parseDate(std::string &line, std::string &date, const std::string &del)
{
	date = line.substr(0, line.find(del));

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

void	BitcoinExchange::parseValue(std::string &line, float &value, const std::string &del)
{
	std::stringstream	ss;
	std::string			valueStr = line.substr(line.find(del) + del.size());
	size_t				countPoint = 0;

	size_t i = (valueStr[0] == '-') ? 1 : 0;
	for (; i < valueStr.size(); i++)
	{
		if (valueStr[i] == '.')
			countPoint++;
		else if (!std::isdigit(valueStr[i]))
			throw BtcException("value invalid format, expected only digit or dot");
	}
	if (countPoint > 1)
		throw BtcException("value invalid format, too many dot");

	ss << valueStr;
	ss >> value;
	if (ss.fail())
		throw BtcException("value invalid format");
	else if (value < 0)
		throw BtcException("value is not a positive number");
}

const std::string		BitcoinExchange::convertToString(const int &n)
{
	std::stringstream ss;

	ss << n;
	return ss.str();
}

float	BitcoinExchange::computeResult(const std::string &date, const float &value)
{
	if (m_dateRateMap.find(date) != m_dateRateMap.end())
		return value * m_dateRateMap.at(date);

	std::map<std::string,float>::iterator prevIt = m_dateRateMap.begin();

	for (std::map<std::string,float>::iterator it = m_dateRateMap.begin(); it != m_dateRateMap.end(); prevIt = it++)
	{
		if (it->first > date)
			break ;
	}
	return value * prevIt->second;
}

void	BitcoinExchange::display(void)
{
	std::string			line;
	std::string			date;
	float				value;

	std::getline(m_inputFile, line);
	if (line != "date | value")
		throw BtcException("input title invalid format, Expected: date | value");
	std::getline(m_inputFile, line);
	while (!line.empty() || !m_inputFile.eof())
	{
		try
		{
			parseDate(line, date, " | ");
			parseValue(line, value, " | ");
			if (value > 1000)
				throw BtcException("too large number");
			float res = computeResult(date, value);
			std::cout << date << " => " << value << " = " << res << std::endl;
		}
		catch(const BitcoinExchange::BtcException& e)
		{
			std::cerr << "IN - Error: " << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "IN - Error: " << e.what() << std::endl;
		}
		line.clear();
		std::getline(m_inputFile, line);
	}
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
