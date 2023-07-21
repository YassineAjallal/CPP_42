/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:09:48 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:39:45 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea";
}

Brain::Brain(Brain& copy)
{
	std::cout << "Brain : Copy constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy)
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
	return (*this);
}


Brain::~Brain()
{
	std::cout << "Brain : Default Destructor called" << std::endl;
}
