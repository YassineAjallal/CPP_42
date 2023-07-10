/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:41 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/10 16:06:18 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::fill_info()
{
	std::cout << "first name : ";
	getline(std::cin, this->first_name);
	std::cout << "last name : ";
	getline(std::cin, this->last_name);
	std::cout << "nickname : ";
	getline(std::cin, this->nickname);
	std::cout << "darkest secret : ";
	getline(std::cin, this->darkest_secret);
	std::cout << "phone number : ";
	getline(std::cin, this->phone_number);
}

int Contact::empty_field()
{
	if (this->first_name.empty() || this->last_name.empty()
		|| this->nickname.empty() || this->darkest_secret.empty()
		|| this->phone_number.empty())
		return (0);
	return (1);
}
void Contact::print_info()
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
}

