/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:23:27 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 09:26:07 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat: Default constructor called;" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	_type = type;
	std::cout << "WrongCat: constructor called;" << std::endl;
}
WrongCat::WrongCat(WrongCat& copy)
{
	*this = copy;
	std::cout << "WrongCat: Copy constructor called;" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called;" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat : Meow" << std::endl;
}

std::string WrongCat::getType() const
{
	return (_type);
}