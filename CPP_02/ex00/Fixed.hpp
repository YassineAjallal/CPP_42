/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:41:45 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/15 18:42:48 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed( const Fixed& copy );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
		Fixed& operator=( const Fixed& copy);

	private:
		int _fixedPoint;
		static const int _nbBits;
};

#endif