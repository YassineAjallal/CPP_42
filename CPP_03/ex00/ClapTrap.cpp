/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:37:22 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/23 16:20:18 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_name = "default_name";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;	
}

ClapTrap& ClapTrap::operator=(ClapTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points > 0)
	{	
		std::cout << "ClapTrap " << _name << " attaks " << target << ", causing " << _attack_damage << " points of damage;"<< std::endl;
		_energy_points--;
	}
	else
		std::cout << "ClapTrap " << _name << " : No energy point" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hit_points)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " : is died" << std::endl;
	}
	else
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " has taken damage;" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0)
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << "ClapTrap " << _name << " has repaired itself;" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " : No energy point" << std::endl;
}