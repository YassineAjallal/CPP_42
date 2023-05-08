/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:36:59 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/08 16:03:01 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string type)
{
	Weapon::_type = type;
}
Weapon::Weapon()
{
}
const std::string&  Weapon::getType()
{
	const std::string& type = Weapon::_type;
	return (type);
}
void  Weapon::setType(std::string new_value)
{
	std::cout << "----->" << Weapon::_type << std::endl;
	Weapon::_type = new_value;
	std::cout << "----->" << Weapon::_type << std::endl;
}