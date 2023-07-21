/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:13:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 12:33:01 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor called;" << std::endl;
	_type = "Cat";
	_cat_brain = new Brain;
}

Cat::Cat(Cat& copy)
{
	*this = copy;
	std::cout << "Cat: Copy constructor called;" << std::endl;
}
Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		_cat_brain= new Brain;
	}
	return (*this);
}

Cat::~Cat()
{
	delete _cat_brain;
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