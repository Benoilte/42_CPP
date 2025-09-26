#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	try
	{
		if (argc == 2)
		{
			BitcoinExchange btc(argv[1]);
			btc.init();
			btc.display();
		}
		else if (argc < 2)
			throw BitcoinExchange::BtcException("input file is missing");
		else
			throw BitcoinExchange::BtcException("Too many argument");
	}
	catch(const BitcoinExchange::BtcException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}

