/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:42:07 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:38:14 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Default Type";
	std::cout << "Animal : Default constructor called;" << std::endl;
}
Animal::Animal(Animal& copy)
{
	std::cout << "Animal : Copy constructor called;" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal : make sound" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal : destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}