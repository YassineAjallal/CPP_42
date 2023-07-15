/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:28:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/14 16:04:48 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i;
	Zombie* zombies = new Zombie[N];

	i = 0;
	while(i < N)
	{
		zombies[i].setName(name);
		zombies[i].announce();
		i++;
	}
	return (zombies);
}