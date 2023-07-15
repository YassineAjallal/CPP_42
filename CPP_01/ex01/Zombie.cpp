/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:27:24 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/15 12:32:59 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
	_name = name;
}
Zombie::~Zombie()
{
	std::cout << _name << " destroyed" << std::endl;
}
void Zombie::announce (void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}