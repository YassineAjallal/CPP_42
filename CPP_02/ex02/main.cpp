/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:41:03 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/22 12:18:23 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout <<  b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;


	Fixed c(1);
	Fixed d(5);
	int comp;

	std::cout << "A : " << c << std::endl;
	std::cout << "B : " << d << std::endl << std::endl << std::endl;

	std::cout << "+ :" << c + d << std::endl;
	std::cout << "* :" << c * d << std::endl;
	std::cout << "/ :" << c / d << std::endl;
	std::cout << "- :" << c - d << std::endl << std::endl;

	comp = (c > d);
	std::cout << "> : " << comp << std::endl;
	comp = (c < d);
	std::cout << "< : " << comp << std::endl;
	comp = (c >= d);
	std::cout << ">= : " <<comp << std::endl;
	comp = (c <= d);
	std::cout << "<= : " <<comp << std::endl;
	comp = (c != d);
	std::cout << "!= : " <<comp << std::endl;
	comp = (c == d);
	std::cout << "== : " <<comp << std::endl << std::endl;


	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;

	return 0;
}