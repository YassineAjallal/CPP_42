/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:38:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/23 17:22:13 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap p1;
	std::cout << "---" << std::endl;
	ScavTrap p2;
	std::cout << "---" << std::endl;
	FragTrap p3;
	std::cout << "-----------------------" << std::endl;
	p1.attack("h");
	p2.attack("h");
	p3.attack("h");
	p2.guardGate();
	p3.highFivesGuys();
	std::cout << "-----------------------" << std::endl;
}