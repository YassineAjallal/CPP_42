/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:58:09 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/16 19:23:19 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array 
{
	private :
		T* _element;
		int _size;
	public :
		Array()
		{
			this->_element = NULL;
			this->_size = 0;
		}
		Array(unsigned int n)
		{
			try
			{
				this->_element = new T[n];
				this->_size = n;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		Array(const Array& copy)
		{
			this->_element = NULL;
			*this = copy;
		}
		Array& operator=(const Array& assign)
		{
			try
			{
				if (this->_element != NULL)
					delete[] this->_element;
				this->_element = new T[assign.size()];
				this->_size = assign.size();
				int i;
				for(i = 0; i < assign.size(); i++)
					this->_element[i] = assign._element[i];
				
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			return (*this);
		}
		T& operator[](int index)
		{
			if (index < 0 || index >= this->_size)
				throw std::out_of_range("index is out of range");
			return (this->_element[index]);
		}
		int size() const
		{
			return (this->_size);
		}
		~Array()
		{
			if (this->_element != NULL)
				delete[] this->_element;
		}
			
};
#endif