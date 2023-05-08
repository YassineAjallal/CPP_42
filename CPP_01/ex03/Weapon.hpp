/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:19:56 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/08 15:28:01 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string _type;

public:
	Weapon();
	Weapon(std::string type);
	const std::string&  getType();
	void  setType(std::string new_value);
};
#endif

