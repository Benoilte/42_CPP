#include "Harl.hpp"

Harl::Harl()
{
	/*Constructor*/
}

Harl::~Harl()
{
	/*Destructor*/
}

void Harl::complain(std::string level)
{
	const std::string   complaintValue[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t              levelNumber = 4;

	for (size_t i = 0; i < 4; i++)
		if (level.compare(complaintValue[i]) == 0) levelNumber = i;
	switch(levelNumber) 
	{
		case 0:
			_debug();
			std::cout << std::endl;
		case 1:
			_info();
			std::cout << std::endl;
		case 2:
			_warning();
			std::cout << std::endl;
		case 3:
			_error();
			break ;
		default:
			std::cout << "Harl Dorl do not know your complaint. Try again with DEBUG, INFO, WARNING or ERROR. Speak loudly, capital letter is important for Harl." << std::endl;
	}
}

void Harl::_debug(void)
{
	std::cout << "[DEBUG]\n" 
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
	<< "I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "[INFO]\n"
	<< "I cannot believe adding extra bacon costs more money.\n"
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "[WARINING] "
	<< "I think I deserve to have some extra bacon for free.\n"
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}