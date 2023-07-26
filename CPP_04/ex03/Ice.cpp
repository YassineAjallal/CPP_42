/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:49:31 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/25 18:31:17 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(const Ice &copy)
{
	*this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

void  Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *clone_ice = new Ice();
	return (clone_ice);
}

Ice::~Ice(){}
