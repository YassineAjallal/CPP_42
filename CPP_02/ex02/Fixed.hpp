/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:41:45 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/22 13:29:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _rawBits;
		static const int _nbBits;
	public:
		Fixed(void);
		Fixed( const Fixed& copy );
		Fixed(const int n);
		Fixed(const float float_point);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
		Fixed& operator=( const Fixed& copy );
		bool operator>( const Fixed& other_side);
		bool operator<( const Fixed& other_side);
		bool operator>=( const Fixed& other_side);
		bool operator<=( const Fixed& other_side);
		bool operator==( const Fixed& other_side);
		bool operator!=( const Fixed& other_side);

		Fixed operator+( const Fixed& other_side);
		Fixed operator-( const Fixed& other_side);
		Fixed operator*( const Fixed& other_side);
		Fixed operator/( const Fixed& other_side);
	
		Fixed& operator--();
		Fixed& operator++();
		Fixed operator--(int);
		Fixed operator++(int);

		static Fixed& min( Fixed& fixed_one, Fixed& fixed_two );
		static Fixed& max( Fixed& fixed_one, Fixed& fixed_two );

		static const Fixed& min( const Fixed& fixed_one, const Fixed& fixed_two );
		static const Fixed& max( const Fixed& fixed_one, const Fixed& fixed_two );
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );
#endif