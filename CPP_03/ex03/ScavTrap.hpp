/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:17:57 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/19 15:50:36 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:
	ScavTrap();
	ScavTrap(ScavTrap& copy);
	ScavTrap(std::string name);
	void guardGate();
	ScavTrap& operator=(ScavTrap& copy);
	void attack(const std::string& target);
	~ScavTrap();
};

#endif