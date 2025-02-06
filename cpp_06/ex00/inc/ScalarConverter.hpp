#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <math.h> 

#define INT_LENGTH_MAX 	10

class ScalarConverter
{
private:
	// CONSTRUCTOR //

	ScalarConverter();
	ScalarConverter(const ScalarConverter &t_src);

	// DESTRUCTOR //

	~ScalarConverter();

	// OPERATOR OVERLOAD //

	ScalarConverter &operator=(const ScalarConverter &t_rhs);

	// PRIVATE ATTRIBUTE //

	// PRIVATE MEMBER FUNCTION //

	// PRIVATE STATIC FUNCTION //

	static void printEmptyStr();
	static void printChar(double t_d);
	static void printInteger(double t_d);

	static bool	isInteger(double t_d);
	static bool	isInteger(std::string t_str);

	static void convertInt(std::string t_str);
	static void convertChar(std::string t_str);

public:
	// GETTER //

	static void convert(std::string t_str);

	// SETTER //

	// PUBLIC MEMBER FUNCTION //
};

#endif
