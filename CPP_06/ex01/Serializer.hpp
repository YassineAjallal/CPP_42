/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:19:29 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 16:06:13 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer {
	public:
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer & operator=(const Serializer &assign);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
};

#endif // Serializer_HPP
