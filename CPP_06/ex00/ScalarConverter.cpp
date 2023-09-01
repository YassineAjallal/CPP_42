/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:09 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 16:58:45 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
    std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
    std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
    (void) assign;
    return *this;
}

void ScalarConverter::convert(std::string str)
{
	int			i;
	bool		is_float;
	bool		is_pseudo_float;
	bool		is_pseudo_double;
	std::string pseudos_float[4] = {"+inff", "-inff", "nanf", "inff"};
	std::string pseudos_double[4] = {"+inf", "-inf", "nan", "inf"};

	is_pseudo_float = false;
	is_pseudo_double = false;
	is_float = false;
	for (i = 0; i < 4; i++)
	{
		if (pseudos_float[i] == str)
		{
			is_pseudo_float = 1;
			break;
		}
		else if (pseudos_double[i] == str)
		{
			is_pseudo_double = 1;
			break;
		}
	}
	if (str.length() == 1 && !std::isdigit(str[0]))
		ScalarConverter::charToOther(str, is_pseudo_double, is_pseudo_float);
	else if (str.find('.') != std::string::npos || is_pseudo_double || is_pseudo_float)
	{
		
		if (!is_pseudo_float && str[str.length() - 1] == 'f' && !is_pseudo_double)
		{
			str.erase(str.length() - 1, 1);
			is_float = 1;
		}
		if (is_float || is_pseudo_float)
			ScalarConverter::floatToOther(str, is_pseudo_float);
		else
			ScalarConverter::floatToOther(str, is_pseudo_double);
	}
	else
		ScalarConverter::intToOther(str);
}

void ScalarConverter::floatToOther(std::string str, bool is_pseudo_float)
{
	double number;
	char *end;

	number = strtod(str.c_str(), &end);
	if (*end != '\0' && !is_pseudo_float)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		ScalarConverter::toChar(static_cast <int> (number), is_pseudo_float);
		ScalarConverter::toInt(static_cast <long> (number), is_pseudo_float);
		ScalarConverter::toFloat(number, str);
		ScalarConverter::toDouble(number, str);
	}
}

void ScalarConverter::doubleToOther(std::string str, bool is_pseudo_double)
{
	double number;
	char *end;

	number = strtod(str.c_str(), &end);
	if (*end != '\0' && !is_pseudo_double)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		ScalarConverter::toChar(static_cast <int> (number), is_pseudo_double);
		ScalarConverter::toInt(static_cast <long> (number), is_pseudo_double);
		ScalarConverter::toFloat(number, str);
		ScalarConverter::toDouble(number, str);
	}
}

void ScalarConverter::intToOther(std::string str)
{
	long int 	integer;
	char *end;
	integer = strtol(str.c_str(), &end, 10);
	if (*end != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		ScalarConverter::toChar(static_cast <int> (integer), 0);
		ScalarConverter::toInt(integer, 0);
		ScalarConverter::toFloat(static_cast <double> (integer), str);
		ScalarConverter::toDouble(static_cast <double> (integer), str);
	}
}

void ScalarConverter::charToOther(std::string str, bool is_pseudo_double, bool is_pseudo_float)
{
	(is_pseudo_double || is_pseudo_float) ? ScalarConverter::toChar(str[0], 1) : ScalarConverter::toChar(str[0], 0);
	(is_pseudo_double || is_pseudo_float) ? ScalarConverter::toInt(static_cast <long int> (str[0]), 1) : ScalarConverter::toInt(static_cast <long int> (str[0]), 0);
	ScalarConverter::toFloat(static_cast <double> (str[0]), str);
	ScalarConverter::toDouble(static_cast <double> (str[0]), str);
}


void ScalarConverter::toFloat(double nb, std::string str)
{
	float convertedNb;
	std::streamsize precision;
	if (nb == -HUGE_VAL)
		std::cout << "float: -inff" << std::endl;
	else if (nb == HUGE_VAL)
		std::cout << "float: +inff" << std::endl;
	else if (nb != nb)
		std::cout << "float: nanf" << std::endl;
	else
	{
		convertedNb = static_cast <float> (nb);
		precision = std::cout.precision();
		std::cout << ((str.find('e') != std::string::npos) ? std::scientific : std::fixed);
		if (str.find('.') != std::string::npos)
		{
			if (str.find('e') != std::string::npos)
				std::cout << std::setprecision(precision - 1);
			else if (str.length() - str.find('.') - 1 == 0)
				std::cout << std::setprecision(1);
			else
				std::cout << std::setprecision(str.length() - str.find('.') - 1);
		}
		else
			std::cout << std::setprecision(1);
		std::cout << "float: " << convertedNb << 'f' << std::endl;
	}
		
}
void ScalarConverter::toDouble(double nb, std::string str)
{
	double convertedNb;
	std::streamsize precision;

	if (nb == -HUGE_VAL)
		std::cout << "double: -inf" << std::endl;
	else if (nb == HUGE_VAL)
		std::cout << "double: +inf" << std::endl;
	else if (nb != nb)
		std::cout << "float: nan" << std::endl;
	else
	{
		convertedNb = static_cast <double> (nb);
		precision = std::cout.precision();
		std::cout << std::fixed;
		std::cout << ((str.find('e') != std::string::npos) ? std::scientific : std::fixed);
		if (str.find('.') != std::string::npos)
		{
			if (str.find('e') != std::string::npos)
				std::cout << std::setprecision(precision - 1);
			else if (str.length() - str.find('.') - 1 == 0)
				std::cout << std::setprecision(1);
			else
				std::cout << std::setprecision(str.length() - str.find('.') - 1);
		}
		else
			std::cout << std::setprecision(1);
			
		std::cout << "double: " << convertedNb << std::endl;
	}
}
void ScalarConverter::toInt(long int nb, bool is_pseudo)
{
	int convertedNb;
	if (nb > INT_MAX || nb < INT_MIN || is_pseudo)
		std::cout << "int: impossible" << std::endl;
	else
	{
		convertedNb = static_cast <int> (nb);
		
		std::cout << "int: " << convertedNb << std::endl;
	}
	
}
void ScalarConverter::toChar(int nb, bool is_pseudo)
{
	char convertedNb;
	if (nb > 127 || nb < 0 || is_pseudo)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(nb))
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		convertedNb = static_cast <char> (nb);
		std::cout << "char: \'" << convertedNb << "\'" << std::endl;
	}
}