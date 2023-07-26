/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:38:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/23 17:26:21 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap t1("yassine");
	std::cout << "---------------------" << std::endl;
	t1.takeDamage(10);
	std::cout << "---------------------" << std::endl;
	t1.attack("h");
	std::cout << "---------------------" << std::endl;
	t1.whoAmI();
	std::cout << "---------------------" << std::endl;
	// FragTrap p;
	// p.attack("hhhh");
}