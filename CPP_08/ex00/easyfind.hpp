/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:38:37 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 00:37:36 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T elements, int to_find)
{
	typename T::iterator it;
	it = std::find(elements.begin(), elements.end(), to_find);
	if (it == elements.end())
		std::cerr << to_find << " doesn't have any occurrance" << std::endl;
	else
		std::cout << to_find << " have an occurrance" << std::endl;
}
#endif