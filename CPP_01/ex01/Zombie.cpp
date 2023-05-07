/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:27:24 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/07 18:07:38 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string name)
{
	Zombie::_name = name;
}
Zombie::Zombie(){};
Zombie::~Zombie()
{
	// std::cout << Zombie::_name << " destroyed" << std::endl;
}
void Zombie::announce (void)
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}