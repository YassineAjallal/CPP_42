/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:19:36 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/08 12:23:22 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACTS_H__
#define	__CONTACTS_H__

#include "contacts.h"

class Contact {

public : 
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string darkest_secret;
	long long 	phone_number;

	void fill_info()
	{
		std::cout << "\e[0;34mfirst name :\e[0;00m ";
		std::cin >> this->first_name;
		std::cout << "\e[0;34mlast name :\e[0;00m ";
		std::cin >> this->last_name;
		std::cout << "\e[0;34mnickname :\e[0;00m ";
		std::cin >> this->nickname;
		std::cout << "\e[0;34mdarkest secret :\e[0;00m ";
		std::cin >> this->darkest_secret;
		std::cout << "\e[0;34mphone number :\e[0;00m ";
		std::cin >> this->phone_number;
	}
	void print_info()
	{
		std::cout << "\e[1;33mfirst name :\e[0;00m " << this->first_name << std::endl;
		std::cout << "\e[1;33mlast name :\e[0;00m " << this->last_name << std::endl;
		std::cout << "\e[1;33mnickname :\e[0;00m " << this->nickname << std::endl;
		std::cout << "\e[1;33mdarkest secret :\e[0;00m " << this->darkest_secret << std::endl;
		std::cout << "\e[1;33mphone number :\e[0;00m " << this->phone_number << std::endl;
	}
};

class PhoneBook {
public :
	Contact contacts[8];
	int nb_contact;
	int old_contact;
	void print_contact()
	{
		int i;
		int search;

		i = 0;
		while (i < this->nb_contact)
		{
			std::cout << i << " | ";
			aligned(this->contacts[i].first_name);
			std::cout << " | ";
			aligned(this->contacts[i].last_name);
			std::cout << " | ";
			aligned(this->contacts[i].nickname);
			std::cout << " | " << std::endl;
			i++;
		}
		std::cout << "\e[0;36msearch :\e[0;00m ";
		std::cin >> search;
		if (search >= this->nb_contact || search < 0)
			std::cout << "contact not found" << std::endl;
		else
			this->contacts[search].print_info();
	}
};
#endif