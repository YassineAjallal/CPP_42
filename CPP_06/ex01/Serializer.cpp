/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:19:32 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/10 23:31:09 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
    std::cout << "\e[0;33mDefault Constructor called of Serializer\e[0m" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of Serializer\e[0m" << std::endl;
}

// Destructor
Serializer::~Serializer()
{
    std::cout << "\e[0;31mDestructor called of Serializer\e[0m" << std::endl;
}

// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
    (void) assign;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *> (raw));
}
