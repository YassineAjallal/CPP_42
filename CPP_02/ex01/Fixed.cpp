/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/22 13:28:53 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (n << _nbBits);
}

Fixed::Fixed(const float float_point)
{
	std::cout << "Float constructor called" << std::endl; 
	this->_rawBits = std::roundf(float_point * (1 << _nbBits));
}
Fixed::Fixed( const Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}


Fixed& Fixed::operator=( const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
    os << fixed.toFloat();
    return os;
}


float Fixed::toFloat( void ) const
{
	float to_float;
	to_float = (float)this->_rawBits / (1 << _nbBits);
	return (to_float);
}
int Fixed::toInt( void ) const
{
	int to_int;
	to_int = (this->_rawBits >> _nbBits);
	return (to_int);
}