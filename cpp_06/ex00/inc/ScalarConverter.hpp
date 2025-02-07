#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
#include <math.h>

#include "colors.hpp"

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
	static void printInfinity(double t_d);

	static void printChar(double t_d);
	static void printChar(float t_f);
	static void printChar(int t_n);

	static void printInteger(double t_d);
	static void printInteger(float t_f);

	static bool	isInteger(double t_d);
	static bool	isInteger(float t_f);
	static bool	isInteger(std::string t_str);

	static void convertFromChar(std::string t_str);
	static void convertFromInt(std::string t_str);
	static void convertFromFloat(std::string t_str);
	static void convertFromDouble(std::string t_str);

	static void defineType(std::string t_str);

public:
	// GETTER //

	static void convert(std::string t_str);

	// SETTER //

	// PUBLIC MEMBER FUNCTION //
};

#endif
