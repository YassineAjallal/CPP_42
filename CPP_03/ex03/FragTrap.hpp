/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:17:57 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/19 15:18:46 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

public:
	FragTrap();
	FragTrap(FragTrap& copy);
	FragTrap(std::string name);
	void highFivesGuys(void);
	FragTrap& operator=(FragTrap& copy);
	~FragTrap();
};

#endif