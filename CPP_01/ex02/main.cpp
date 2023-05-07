/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:15:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/07 18:29:06 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "string address    : " << &str <<std::endl;
	std::cout << "stringPTR address : " << stringPTR <<std::endl;
	std::cout << "stringREF address : " << &stringREF <<std::endl;

	std::cout << "string value      : " << str <<std::endl;
	std::cout << "stringPTR value   : " << *stringPTR <<std::endl;
	std::cout << "stringREF value   : " << stringREF <<std::endl;
}