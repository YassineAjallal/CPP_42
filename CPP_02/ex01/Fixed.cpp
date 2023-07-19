/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/18 12:42:40 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = (n << _nbBits);
}

Fixed::Fixed(const double float_point)
{
	std::cout << "Float constructor called" << std::endl; 
	_fixedPoint = std::roundf(float_point * (1 << _nbBits));
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
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}


Fixed& Fixed::operator=( const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_fixedPoint = copy.getRawBits();
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
	to_float = (float)_fixedPoint / (1 << _nbBits);
	return (to_float);
}
int Fixed::toInt( void ) const
{
	int to_int;
	to_int = (_fixedPoint >> _nbBits);
	return (to_int);
}

const int Fixed::_nbBits = 8;