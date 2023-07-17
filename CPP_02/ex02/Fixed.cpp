/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/17 22:34:00 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixedPoint = 0;
}
Fixed::Fixed(const int n)
{
	_fixedPoint = (n << _nbBits);
}

Fixed::Fixed(const double float_point)
{
	_fixedPoint = std::roundf(float_point * (1 << _nbBits));
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
	return (this->toFloat());
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
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

Fixed& Fixed::operator=( const Fixed& copy)
{
	if (this != &copy)
		_fixedPoint = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>( const Fixed& other_side)
{
	return (_fixedPoint > other_side.getRawBits());
}

bool Fixed::operator<( const Fixed& other_side)
{
	return (_fixedPoint < other_side.getRawBits());
}

bool Fixed::operator>=( const Fixed& other_side)
{
	return (_fixedPoint >= other_side.getRawBits());
}

bool Fixed::operator<=( const Fixed& other_side)
{
	return (_fixedPoint <= other_side.getRawBits());
}

bool Fixed::operator==( const Fixed& other_side)
{
	return (_fixedPoint == other_side.getRawBits());
}

bool Fixed::operator!=( const Fixed& other_side)
{
	return (_fixedPoint != other_side.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other_side)
{
	Fixed add_op;

	add_op.setRawBits( _fixedPoint + other_side.getRawBits() );
	return (add_op);
}

Fixed Fixed::operator-(const Fixed& other_side)
{
	Fixed sub_op;

	sub_op.setRawBits( _fixedPoint - other_side.getRawBits() );
	return (sub_op);
}

Fixed Fixed::operator*(const Fixed& other_side)
{
	Fixed mult_op;

	mult_op.setRawBits( _fixedPoint * other_side.getRawBits() );
	return (mult_op);
}

Fixed Fixed::operator/(const Fixed& other_side)
{
	Fixed div_op;

	div_op.setRawBits( _fixedPoint / other_side.getRawBits() );
	return (div_op);
}

Fixed& Fixed::operator--()
{
	--_fixedPoint;
	return (*this);
}

Fixed& Fixed::operator++()
{
	++_fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_fixedPoint;
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_fixedPoint;
	return (tmp);
}

Fixed& Fixed::min( Fixed& fixed_one, Fixed& fixed_two )
{
	return (fixed_one.getRawBits() < fixed_two.getRawBits() ? fixed_one : fixed_two);
}

Fixed& Fixed::max( Fixed& fixed_one, Fixed& fixed_two )
{
	return (fixed_one.getRawBits() > fixed_two.getRawBits() ? fixed_one : fixed_two);
}

const Fixed& Fixed::min( const Fixed& fixed_one, const Fixed& fixed_two )
{
	return (fixed_one.getRawBits() < fixed_two.getRawBits() ? fixed_one : fixed_two);
}

const Fixed& Fixed::max( const Fixed& fixed_one, const Fixed& fixed_two )
{
	return (fixed_one.getRawBits() > fixed_two.getRawBits() ? fixed_one : fixed_two);
}

const int Fixed::_nbBits = 8;