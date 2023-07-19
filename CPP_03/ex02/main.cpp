/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:38:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/19 12:28:42 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap p1;
	std::cout << "---" << std::endl;
	FragTrap p2;
	std::cout << "---" << std::endl;
	ScavTrap p3;
	std::cout << "-----------------------" << std::endl;
	p1.attack("h");
	p2.attack("h");
	p3.attack("h");
	p2.highFivesGuys();
	p3.guardGate();
	std::cout << "-----------------------" << std::endl;
}