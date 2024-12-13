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
    const levelFunction f[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    const std::string   complaintValue[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++)
    {
        if (level.compare(complaintValue[i]) == 0)
           return (this->*f[i])();
    }
    std::cout << "Harl Dorl do not know your complaint. Try again with DEBUG, INFO, WARNING or ERROR. Speak loudly, capital letter is important for Harl." << std::endl;
}

void Harl::_debug(void)
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "[WARINING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}