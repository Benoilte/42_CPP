#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    /*Constructor*/
}

ScalarConverter::ScalarConverter(const ScalarConverter &t_src)
{
	*this = t_src;

	return ;
}

ScalarConverter::~ScalarConverter()
{
	/*Destructor*/
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &t_rhs)
{
	(void)t_rhs;
	return *this;
}

void ScalarConverter::printEmptyStr()
{
	std::cout <<	"char: Not displayable\n"
					"int: impossible\n"
					"float: nanf\n"
					"double: nan" << std::endl;
}

void ScalarConverter::printChar(double t_d)
{
	std::cout << "char: ";
	if (isInteger(t_d) && std::isgraph(static_cast<int>(t_d)))
		std::cout << static_cast<char>(t_d) << std::endl;
	else
		std::cout << "Not displayable" << std::endl;
}

void ScalarConverter::printInteger(double t_d)
{
	std::cout << "int: ";
	if (isInteger(t_d))
		std::cout << static_cast<int>(t_d) << std::endl;
	else
		std::cout << "Out of range" << std::endl;
}

bool ScalarConverter::isInteger(double t_d)
{
	double intMax = static_cast<double>(std::numeric_limits<int>::max());
	double intMin = static_cast<double>(std::numeric_limits<int>::min());

	return (floor(t_d) >= intMin) && (floor(t_d) <= intMax);
}

bool ScalarConverter::isInteger(std::string t_str)
{
	int		i;
	int		digitSize = 0;

	i = (t_str[0] == '+' || t_str[0] == '-');
	while (std::isdigit(t_str[i]))
	{
		digitSize++;
		i++;
		if (digitSize > INT_LENGTH_MAX)
			return false;
	}

	long int intConverted = atol(t_str.c_str());
	long int intMax = static_cast<long int>(std::numeric_limits<int>::max());
	long int intMin = static_cast<long int>(std::numeric_limits<int>::min());

	return (intConverted >= intMin) && (intConverted <= intMax);
}

// –2147483648
//  2147483647

void ScalarConverter::convertInt(std::string t_str)
{
	int	intStr;

	intStr = atoi(t_str.c_str());
	std::cout << intStr << std::endl;
	// printChar(doubleStr);
	// printInteger(doubleStr);
	return ;
}

void ScalarConverter::convertChar(std::string t_str)
{
	(void)t_str;
	std::cout << "Convert char" << std::endl;
	return ;
}

void ScalarConverter::convert(std::string t_str)
{
	size_t	strSize;

	t_str.erase(0, t_str.find_first_not_of(" \t\n\r\f\v"));
	strSize = t_str.size();
	switch (strSize)
	{
		case 0:
			printEmptyStr();
			break;
	
		case 1:
			if (std::isdigit(t_str[0]))
				convertInt(t_str);
			else
				convertChar(t_str);
			break;
	
		default:
			convertInt(t_str);
			break;
	}
}