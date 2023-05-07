/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:36:01 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/07 18:13:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie *zombies;
	int i;

	zombies = zombieHorde(5, "yassine");
	i = 0;
	while (i < 5)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
}