/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:09 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 16:06:03 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	Data* data = new Data("foo");
	Data *data1;
	uintptr_t t;
	std::cout << "before : "<< data->getName() << "\t" << data << std::endl;
	t = Serializer::serialize(data);
	data1 = Serializer::deserialize(t);
	std::cout << "after  : "<< data1->getName() << "\t" << data1 << std::endl;
	delete data;
	return 0;
}
