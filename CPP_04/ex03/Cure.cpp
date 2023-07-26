/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:05:58 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/25 18:31:40 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure &copy)
{
	*this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

void  Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *clone_cure = new Cure();
	return (clone_cure);
}

Cure::~Cure(){}