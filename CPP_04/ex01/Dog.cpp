/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:46:41 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 12:33:08 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called;" << std::endl;
	_type = "Dog";
	_dog_brain = new Brain;
}
Dog::Dog(Dog& copy)
{
	*this = copy;
	std::cout << "Dog: Copy constructor called;" << std::endl;
}
Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		_dog_brain = new Brain;
	}
	return (*this);
}

Dog::~Dog()
{
	delete _dog_brain;
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
