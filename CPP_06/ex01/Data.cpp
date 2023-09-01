/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:23:26 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/10 23:27:22 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Constructors
Data::Data() : _name("default_name")
{
    std::cout << "\e[0;33mDefault Constructor called of Data\e[0m" << std::endl;
}
Data::Data(std::string name) : _name(name)
{
    std::cout << "\e[0;33mParametrized Constructor called of Data\e[0m" << std::endl;
}
Data::Data(const Data &copy) : _name(copy.getName())
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of Data\e[0m" << std::endl;
}

// Destructor
Data::~Data()
{
    std::cout << "\e[0;31mDestructor called of Data\e[0m" << std::endl;
}

// Operators
Data & Data::operator=(const Data &assign)
{
    this->_name = assign.getName();
    return *this;
}

std::string Data::getName() const
{
	return (this->_name);
}