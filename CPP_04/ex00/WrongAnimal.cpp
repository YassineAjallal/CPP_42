/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:20:14 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 09:26:01 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "Default Type";
	std::cout << "WrongAnimal : Default constructor called;" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	std::cout << "WrongAnimal : Copy constructor called;" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal : make sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}