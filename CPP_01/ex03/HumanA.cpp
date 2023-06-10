/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:20:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/06/10 20:52:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	HumanA::name = name;
	HumanA::weapon = &weapon;
}

void HumanA::attack()
{	
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
