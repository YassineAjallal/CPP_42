/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/23 03:50:47 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "ctime"
#include <unistd.h>


int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange btc;
			btc.bitcoinExchange("data.csv", av[1]);
		}
		catch (BitcoinExchange::BitcoinExchangeExceptions &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage : ./btc [ input_file ]" << std::endl;
	return (0);

}