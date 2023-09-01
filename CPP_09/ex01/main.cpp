/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/24 01:21:30 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac == 2)
		RPN::rpn_calculator(av[1]);
	else
		std::cout << "Usage : ./RPN \"numbers\"" << std::endl;
	return (0);
}