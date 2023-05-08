/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:28:15 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/08 15:35:07 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {

public:
	
	Weapon weapon;
	std::string name;

	HumanB(std::string name);
	void setWeapon(Weapon weapon);
	void attack();

};

#endif