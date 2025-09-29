#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <exception>

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

		std::string		m_todayDate;
		std::string		m_inputStr;
		std::ifstream	m_inputFile;
		std::ifstream	m_dataBaseFile;

		void	initDataBase();
		void	parseDate(std::string &line, std::string &date);
		void	validYear(const std::string &date, const int &year);
		void	validMonth(const std::string &date, const int &month);
		void	validDay(const std::string &date, const int &year, const int &month, const int &day);
		bool	isLeapYear(const int &year);
		void	parseExchangeRate(std::string &line, float &exchangeRate);
		const std::string	convertToString(const int &n);
};

std::ostream	&operator<<(std::ostream &out, BitcoinExchange const &rhs);

#endif
