#include "utils.hpp"

void	testDefault(void)
{
	std::cout << CYAN << "./convert ''" << RESET << std::endl;
	ScalarConverter::convert("");

	std::cout << CYAN << "\n./convert '      '" << RESET << std::endl;
	ScalarConverter::convert("       ");

	std::cout << CYAN << "\n./convert inf" << RESET << std::endl;
	ScalarConverter::convert("inf");

	std::cout << CYAN << "\n./convert -inf" << RESET << std::endl;
	ScalarConverter::convert("-inf");

	std::cout << CYAN << "\n./convert nan" << RESET << std::endl;
	ScalarConverter::convert("nan");

	std::cout << CYAN << "\n./convert -nan" << RESET << std::endl;
	ScalarConverter::convert("-nan");

	std::cout << CYAN << "\n./convert inff" << RESET << std::endl;
	ScalarConverter::convert("inff");

	std::cout << CYAN << "\n./convert -inff" << RESET << std::endl;
	ScalarConverter::convert("-inff");

	std::cout << CYAN << "\n./convert nanf" << RESET << std::endl;
	ScalarConverter::convert("nanf");

	std::cout << CYAN << "\n./convert -nanf" << RESET << std::endl;
	ScalarConverter::convert("-nanf");

	std::cout << CYAN << "\n./convert a" << RESET << std::endl;
	ScalarConverter::convert("a");

	std::cout << CYAN << "\n./convert 0" << RESET << std::endl;
	ScalarConverter::convert("0");

	std::cout << CYAN << "\n./convert 0.0" << RESET << std::endl;
	ScalarConverter::convert("0.0");

	std::cout << CYAN << "\n./convert 0.0f" << RESET << std::endl;
	ScalarConverter::convert("0.0f");

	std::cout << CYAN << "\n./convert +42" << RESET << std::endl;
	ScalarConverter::convert("+42");

	std::cout << CYAN << "\n./convert +4.2" << RESET << std::endl;
	ScalarConverter::convert("+4.2");

	std::cout << CYAN << "\n./convert +4.2f" << RESET << std::endl;
	ScalarConverter::convert("+4.2f");

	std::cout << CYAN << "\n./convert 2147483647" << RESET << std::endl;
	ScalarConverter::convert("2147483647");

	std::cout << CYAN << "\n./convert 2147483648" << RESET << std::endl;
	ScalarConverter::convert("2147483648");

	std::cout << CYAN << "\n./convert -2147483648" << RESET << std::endl;
	ScalarConverter::convert("-2147483648");

	std::cout << CYAN << "\n./convert -2147483649" << RESET << std::endl;
	ScalarConverter::convert("-2147483649");

	std::cout << CYAN << "\n./convert " << std::numeric_limits<float>::max() << RESET << std::endl;
	ScalarConverter::convert("340282346638528859811704183484516925440.0000000000000000f");

	std::cout << CYAN << "\n350282346638528859811704183484516925440.0000000000000000f (bigger than float max)" << RESET << std::endl;
	ScalarConverter::convert("350282346638528859811704183484516925440.0000000000000000f");

	std::cout << CYAN << "\n./convert " << std::numeric_limits<double>::max() << RESET << std::endl;
	ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000");
	
	std::cout << CYAN << "\n./convert 189769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000 (bigger than double max)" << RESET << std::endl;
	ScalarConverter::convert("189769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000");
}

int	main(int argc, char **argv)
{
	// ScalarConverter sc;
	std::string input;

	switch (argc)
	{
		case 1:
			testDefault();
			break;

		case 2:
			input = argv[1];
			ScalarConverter::convert(input);
			break;

		default:
			std::cout << "Available command: " << std::endl;
			std::cout << "'./convert [+-]number[.number[f]]'" << std::endl;
	}
	return (0);
}
