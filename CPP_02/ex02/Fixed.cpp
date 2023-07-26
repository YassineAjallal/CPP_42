/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/22 13:29:06 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed(void)
{
	this->_rawBits = 0;
}
Fixed::Fixed(const int n)
{
	this->_rawBits = (n << _nbBits);
}

Fixed::Fixed(const float float_point)
{
	this->_rawBits = std::roundf(float_point * (1 << _nbBits));
}
Fixed::Fixed( const Fixed& copy )
{
	*this = copy;
}

Fixed::~Fixed(void)
{

}

int Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
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

Fixed& Fixed::operator=( const Fixed& copy)
{
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>( const Fixed& other_side)
{
	return (this->_rawBits > other_side.getRawBits());
}

bool Fixed::operator<( const Fixed& other_side)
{
	return (this->_rawBits < other_side.getRawBits());
}

bool Fixed::operator>=( const Fixed& other_side)
{
	return (this->_rawBits >= other_side.getRawBits());
}

bool Fixed::operator<=( const Fixed& other_side)
{
	return (this->_rawBits <= other_side.getRawBits());
}

bool Fixed::operator==( const Fixed& other_side)
{
	return (this->_rawBits == other_side.getRawBits());
}

bool Fixed::operator!=( const Fixed& other_side)
{
	return (this->_rawBits != other_side.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other_side)
{
	Fixed add_op(this->toFloat() + other_side.toFloat());
	return (add_op);
}

Fixed Fixed::operator-(const Fixed& other_side)
{
	Fixed sub_op(this->toFloat() - other_side.toFloat());
	return (sub_op);
}

Fixed Fixed::operator*(const Fixed& other_side)
{
	Fixed mult_op(this->toFloat() * other_side.toFloat());
	return (mult_op);
}

Fixed Fixed::operator/(const Fixed& other_side)
{
	Fixed div_op(this->toFloat() / other_side.toFloat());
	return (div_op);
}

Fixed& Fixed::operator--()
{
	--this->_rawBits;
	return (*this);
}

Fixed& Fixed::operator++()
{
	++this->_rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->_rawBits;
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->_rawBits;
	return (tmp);
}

Fixed& Fixed::min( Fixed& fixed_one, Fixed& fixed_two )
{
	return (fixed_one < fixed_two ? fixed_one : fixed_two);
}

Fixed& Fixed::max( Fixed& fixed_one, Fixed& fixed_two )
{
	return (fixed_one > fixed_two ? fixed_one : fixed_two);
}

const Fixed& Fixed::min( const Fixed& fixed_one, const Fixed& fixed_two )
{
	return (fixed_one.getRawBits() < fixed_two.getRawBits() ? fixed_one : fixed_two);
}

const Fixed& Fixed::max( const Fixed& fixed_one, const Fixed& fixed_two )
{
	return (fixed_one.getRawBits() > fixed_two.getRawBits() ? fixed_one : fixed_two);
}