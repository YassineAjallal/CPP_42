/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:17:38 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/19 15:50:28 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	_name = "- ScavTrap Default name -";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap& copy)
{
	std::cout << "ScavTrap copy Constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap& copy)
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

void ScavTrap::attack(const std::string& target)
{
	if (_energy_points > 0)
	{	
		std::cout << "ScavTrap " << _name << " attaks " << target << ", causing " << _attack_damage << " points of damage;"<< std::endl;
		_energy_points--;
	}
	else
		std::cout << "ScavTrap " << _name << " : No energy point" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode;" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}