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
	std::cout <<	"char:\tImpossible\n"
					"int:\tImpossible\n"
					"float:\tImpossiblef\n"
					"double:\tImpossible" << std::endl;
}

void ScalarConverter::printImpossibleCharInt()
{
	std::cout <<	"char:\tImpossible\n"
					"int:\tImpossible" << std::endl;
}

void ScalarConverter::printChar(int t_n)
{
	if ((t_n > 0) && (t_n < 255) && std::isgraph(t_n))
		std::cout << "char:\t" << static_cast<char>(t_n) << std::endl;
	else
		std::cout << "char:\tNot displayable" << std::endl;
}

void ScalarConverter::printChar(float t_f)
{
	if ((t_f > 0) && (t_f < 255) && std::isgraph(static_cast<int>(t_f)))
		std::cout << "char:\t" << static_cast<char>(t_f) << std::endl;
	else
		std::cout << "char:\tNot displayable" << std::endl;
}

void ScalarConverter::printChar(double t_d)
{
	if ((t_d > 0) && (t_d < 255) && std::isgraph(static_cast<int>(t_d)))
		std::cout << "char:\t" << static_cast<char>(t_d) << std::endl;
	else
		std::cout << "char:\tNot displayable" << std::endl;
}

void ScalarConverter::printInteger(float t_f)
{
	if (isInteger(t_f))
		std::cout << "int:\t" << static_cast<int>(t_f) << std::endl;
	else
		std::cout << "int:\tOut of range" << std::endl;
}

void ScalarConverter::printInteger(double t_d)
{
	if (isInteger(t_d))
		std::cout << "int:\t" << static_cast<int>(t_d) << std::endl;
	else
		std::cout << "int:\tOut of range" << std::endl;
}

bool ScalarConverter::isInteger(std::string t_str)
{
	long int intConverted = atol(t_str.c_str());
	long int intMax = static_cast<long int>(std::numeric_limits<int>::max());
	long int intMin = static_cast<long int>(std::numeric_limits<int>::min());

	return ((intConverted >= intMin) && (intConverted <= intMax));
}

bool ScalarConverter::isInteger(float t_f)
{
	float intMax = static_cast<float>(std::numeric_limits<int>::max());
	float intMin = static_cast<float>(std::numeric_limits<int>::min());

	return (floorf(t_f) >= intMin) && (floorf(t_f) <= intMax);
}

bool ScalarConverter::isInteger(double t_d)
{
	double intMax = static_cast<double>(std::numeric_limits<int>::max());
	double intMin = static_cast<double>(std::numeric_limits<int>::min());

	return (floor(t_d) >= intMin) && (floor(t_d) <= intMax);
}

void ScalarConverter::convertFromChar(std::string t_str)
{
	char	c;

	std::cout << YELLOW << "Convert from char" << RESET << std::endl;
	c = t_str[0];
	printChar(static_cast<int>(c));
	std::cout << "int:\t" << static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(c) << std::endl;
	return ;
}

void ScalarConverter::convertFromInt(std::string t_str)
{
	int	iStr;

	std::cout << YELLOW << "Convert from int" << RESET << std::endl;
	iStr = atoi(t_str.c_str());
	printChar(iStr);
	std::cout << "int:\t" << iStr << std::endl;
	std::cout << "float:\t" << static_cast<float>(iStr) << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(iStr) << std::endl;
	return ;
}

void ScalarConverter::convertFromFloat(std::string t_str)
{
	float	fStr;
	typedef std::numeric_limits<float> fltLimits;

	std::cout << YELLOW << "Convert from float" << RESET << std::endl;
	fStr = atof(t_str.c_str());
	if ((fStr == fltLimits::infinity()) || (fStr == -(fltLimits::infinity())) || (fStr != fStr))
		printImpossibleCharInt();
	else
	{
		printChar(fStr);
		printInteger(fStr);
	}
	std::cout << "float:\t" << fStr << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(fStr) << std::endl;
	return ;
}

void ScalarConverter::convertFromDouble(std::string t_str)
{
	double	dStr;

	std::cout << YELLOW << "Convert from double" << RESET << std::endl;
	dStr = strtod(t_str.c_str(), NULL);
	if ((dStr == HUGE_VAL) || (dStr == -HUGE_VAL) || (dStr != dStr))
		printImpossibleCharInt();
	else
	{
		printChar(dStr);
		printInteger(dStr);
	}
	std::cout << "float:\t" << static_cast<float>(dStr) << "f" << std::endl;
	std::cout << "double:\t" << dStr << std::endl;
	return ;
}

void ScalarConverter::defineType(std::string t_str)
{
	size_t	i;
	int		digitSize = 0;
	bool	inRange;

	i = (t_str[0] == '+' || t_str[0] == '-');
	while (std::isdigit(t_str[i]))
	{
		i++;
		digitSize++;
	}
	inRange = ((digitSize > 0) && (digitSize <= INT_LENGTH_MAX));
	if (inRange && (t_str[i] != '.') && (t_str[i] != 'f') && isInteger(t_str))
		convertFromInt(t_str);
	else
	{
		std::cout << std::setprecision(5);
		while (std::isdigit(t_str[i]) || (t_str[i] == '.'))
			i++;
		if ((t_str.compare(i, 4, "nanf") == 0) || (t_str.compare(i, 4, "inff") == 0) || (t_str[i] == 'f'))
			convertFromFloat(t_str);
		else
			convertFromDouble(t_str);
	}
}

void ScalarConverter::convert(std::string t_str)
{
	size_t	strSize;
	size_t	posFirstNotSpaces;

	posFirstNotSpaces = t_str.find_first_not_of(" \t\n\r\f\v");
	t_str.erase(0, posFirstNotSpaces);
	strSize = t_str.size();
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	switch (strSize)
	{
		case 0:
			printEmptyStr();
			break;

		case 1:
			if (std::isdigit(t_str[0]))
				convertFromInt(t_str);
			else
				convertFromChar(t_str);
			break;

		default:
			defineType(t_str);
			break;
	}
}
