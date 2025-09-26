#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>

class BitcoinExchange
{


	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

	private:

	std::ifstream	m_input;
};

std::ostream	&operator<<(std::ostream &out, BitcoinExchange const &rhs);

#endif
