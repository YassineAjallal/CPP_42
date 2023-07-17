/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:50:05 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/17 10:24:16 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl; 
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl; 
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNIMG]" << std::endl; 
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl; 
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*harlPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*harlPtr[i])();
			break;
		}
		i++;
	}
}

void Harl::harlFilter(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	i = 0;
	while (level != levels[i] && i < 4)
		i++;

	switch(i)
	{
		case 0 ... 3: 
			while(i < 4) 
			{
				this->complain(levels[i]); 
				i++;
			}
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;		
	}
}