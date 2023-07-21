/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:13:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:38:33 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat: Default constructor called;" << std::endl;
}

Cat::Cat(Cat& copy)
{
	*this = copy;
	std::cout << "Cat: Copy constructor called;" << std::endl;
}
Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called;" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat : Meow" << std::endl;
}

std::string Cat::getType() const
{
	return (_type);
}