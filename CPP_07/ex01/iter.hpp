/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:30:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/16 19:01:14 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
T replace(T a)
{
	a += 1;
	std::cout << a << std::endl;
	return (a);
}

template <typename T, typename Func>
void iter(T &address, size_t length, Func func)
{
	for (size_t i = 0; i < length; i++)
		func(address[i]);
}

#endif