/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:28:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/07 17:42:14 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	int i;
	Zombie* zombies = new Zombie[N]();

	i = 0;
	while(i < N)
	{
		zombies[i] = Zombie(name);
		i++;
	}
	return (zombies);
}

// int val = 1024;
// declare reference : int &refval = val;
// error : a reference must be initialized

/*
	---> when we define a reference, insteat of copying the initializer's value, we BIND the reference to its initializer
	---> error : initializer must be an object
	---> always the initializer and the ref are the same type
*/
