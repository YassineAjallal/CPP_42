/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:36:59 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/15 12:30:13 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}
Weapon::Weapon()
{
}
const std::string&  Weapon::getType()
{
	return (_type);
}
void  Weapon::setType(std::string new_value)
{
	_type = new_value;
}