/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:41:45 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/22 13:28:59 by yajallal         ###   ########.fr       */
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
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );
#endif