/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:33:16 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/25 18:30:35 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "Default Type";
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy)
{
	if (this != &copy)
		this->_type = copy.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria: use function called : " << target.getName() << std::endl;
}

AMateria::~AMateria(){
}