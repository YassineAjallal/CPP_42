/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:38:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/18 17:15:55 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap player1;
	ClapTrap player2("yassine");
	ClapTrap player3(player2);
	
	player1 = player2;
	player1.attack("ajallal");
	player3.attack("imad");
}