#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <ctime>
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
				std::string message;

			public:
				BtcException() throw();
				BtcException(const char* msg) throw();
				virtual ~BtcException() throw();
				virtual const char	*what() const throw();
		};

	private:

		std::string		m_todayDate;
		std::string		m_inputStr;
		std::ifstream	m_inputFile;
};

std::ostream	&operator<<(std::ostream &out, BitcoinExchange const &rhs);

#endif
