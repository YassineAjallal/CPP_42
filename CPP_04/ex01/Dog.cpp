/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:46:41 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 10:01:01 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called;" << std::endl;
	_type = "Dog";
	_dog_brain = new Brain();
}

Dog::Dog(Dog& copy)
{
	std::cout << "Dog: Copy constructor called;" << std::endl;
	_type = copy._type;
	_dog_brain = new Brain();
	*_dog_brain = *copy._dog_brain;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		*_dog_brain = *copy._dog_brain;
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
