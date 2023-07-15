/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:41:45 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/15 23:25:25 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed( const Fixed& copy ); // copy constructor
		Fixed(const int n); // converts (n) to the corresponding fixed-point value
		Fixed(const double float_point); // converts (float_point) to the corresponding fixed-point value
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const; // converts the fixed-point value to a floating-point value
		int toInt( void ) const; // the fixed-point value to an integer value
		~Fixed();
		Fixed& operator=( const Fixed& copy); // copy assignment operator overload
		std::ostream& operator<<(std::ostream& os, const Fixed& insert);
	private:
		int _fixedPoint;
		static const int _nbBits;
};

#endif