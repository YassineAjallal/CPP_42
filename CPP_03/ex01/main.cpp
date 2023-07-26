/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:38:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/23 16:40:44 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	// ClapTrap p1;
	ScavTrap p2("yassine");
	std::cout << "-----------------------" << std::endl;
	// p1.attack("imad");
	p2.attack("imad");
	p2.guardGate();
	std::cout << "-----------------------" << std::endl;
}