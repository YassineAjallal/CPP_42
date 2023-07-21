/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:46:41 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:38:43 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog: Default constructor called;" << std::endl;
}
Dog::Dog(Dog& copy)
{
	*this = copy;
	std::cout << "Dog: Copy constructor called;" << std::endl;
}
Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called;" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog : Bark" << std::endl;
}

std::string Dog::getType() const
{
	return (_type);
}
