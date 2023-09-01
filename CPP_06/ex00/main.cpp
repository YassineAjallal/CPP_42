/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:09 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 15:56:00 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
		std::cerr << "bad usage" << std::endl;
	else
	{
		std::string str = av[1];
		ScalarConverter::convert(str);
	}
	return 0;
}
