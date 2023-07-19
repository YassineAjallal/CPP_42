/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:30:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/19 15:49:54 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_name = "- DiamondTrap default name -";
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
}
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name") , FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_name = name;
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
}
DiamondTrap::DiamondTrap(DiamondTrap &copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}
DiamondTrap& DiamondTrap::operator=(DiamondTrap& copy)
{
	if(this != &copy)
	{
		_name = copy._name;
		_hit_points = copy._hit_points;
		_energy_points = copy._energy_points;
		_attack_damage = copy._attack_damage;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << _name << " - ClapTrap name : " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
