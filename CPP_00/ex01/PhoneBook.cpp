/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:55:37 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/10 12:03:55 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::print_contact()
{
	int i;
	int to_search;
	std::string search;

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
	std::cout << "search : ";
	getline(std::cin, search);
	to_search = std::stoi(search);
	std::cout << to_search << std::endl;
	if (to_search >= this->nb_contact || to_search < 0)
		std::cout << "contact not found" << std::endl;
	else
		this->contacts[to_search].print_info();
}