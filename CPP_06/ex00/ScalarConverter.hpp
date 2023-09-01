/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:05 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 15:55:23 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <climits>



class ScalarConverter {
public:
    ScalarConverter(const ScalarConverter &copy);
    ~ScalarConverter();
    ScalarConverter & operator=(const ScalarConverter &assign);
	static void convert(std::string str);

private:
    ScalarConverter();
	static void floatToOther(std::string str, bool is_pseudo_float);
	static void doubleToOther(std::string str, bool is_pseudo_double);
	static void intToOther(std::string str);
	static void charToOther(std::string str, bool is_pseudo_double, bool is_pseudo_float);
	static void toFloat(double nb, std::string str);
	static void toDouble(double nb, std::string str);
	static void toInt(long int nb, bool is_pseudo);
	static void toChar(int nb, bool is_pseudo);
};

#endif // ScalarConverter_HPP
