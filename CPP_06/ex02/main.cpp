/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:23:20 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 16:14:32 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void testIdentifyPtr( void )
{
	Base *basePtr;
	basePtr = generate();
	identify(basePtr);
}
void testIdentifyRef( void )
{
	Base *basePtr = generate();
	Base &baseRef = *basePtr;
	identify(baseRef);
}

int main( void )
{
	std::cout << "-----------identify Pointer-----------" << std::endl;
	testIdentifyPtr();
	std::cout << "-----------identify Reference---------" << std::endl;
	testIdentifyRef();
	return 0;
}
