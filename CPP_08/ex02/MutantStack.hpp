/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:39:43 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 00:29:23 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::deque<T>::iterator iterator;
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack& copy)  : std::stack<T>(copy) {}
		MutantStack& operator=(MutantStack& assign)
		{
			this->c = assign.c;
			return (*this);
		}
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		~MutantStack() {}	
};
#endif