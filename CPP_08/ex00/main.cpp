/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 01:21:33 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main( void )
{
	std::vector<int> vect;
	for (int i = 0; i < 5; i++)
		vect.push_back(i * 20);
	
	easyfind < std::vector<int> >(vect, 90);
	return 0;
}
