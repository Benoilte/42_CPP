#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <exception>
# include <limits>
# include <iterator>
# include <map>

class BitcoinExchange
{


	public:

		BitcoinExchange();
		BitcoinExchange(const std::string &input);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

		class BtcException : public std::exception
		{
			private:
				std::string m_message;

			public:
				BtcException() throw();
				BtcException(std::string msg) throw();
				virtual ~BtcException() throw();
				virtual const char	*what() const throw();
		};

		void	init();
		void	display();

	private:

		std::string						m_todayDate;
		std::string						m_inputStr;
		std::ifstream					m_inputFile;
		std::ifstream					m_dataBaseFile;
		std::map<std::string, float>	m_dateRateMap;

		void	initDataBase();
		void	parseDate(std::string &line, std::string &date, const std::string &del);
		void	validYear(const std::string &date, const int &year);
		void	validMonth(const std::string &date, const int &month);
		void	validDay(const std::string &date, const int &year, const int &month, const int &day);
		bool	isLeapYear(const int &year);
		void	parseValue(std::string &line, float &exchangeRate, const std::string &del);
		float	computeResult(const std::string &date, const float &value);
		bool	multOverflow(const float &lhs, const float &rhs);

		const std::string	convertToString(const int &n);
};

std::ostream	&operator<<(std::ostream &out, BitcoinExchange const &rhs);

#endif
