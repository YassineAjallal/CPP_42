/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:28:01 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/15 15:06:34 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{

public:
	Zombie();
	~Zombie();
	void announce (void);
	void setName( std::string name );

private:

	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
#endif