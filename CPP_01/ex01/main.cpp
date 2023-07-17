/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:36:01 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/17 10:04:32 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombies;
	zombies = zombieHorde(6, "Foo");
	for(int i = 0; i < 6; i++)
		zombies[i].announce();
	delete[] zombies;
}