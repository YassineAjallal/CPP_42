/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:13:15 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/10 12:16:50 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;
	std::string command;
	book.nb_contact = 0;
	int old_contact = 0;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) : ";
		getline(std::cin, command);
		if (std::cin.eof())
			std::cout << "command INVALID"<< std::endl;
		if (command == "ADD")
		{
			if (book.nb_contact > 7)
			{
				book.contacts[old_contact].fill_info();
				if (book.contacts[old_contact].empty_field())	
					old_contact++;
				if (old_contact > 7)
					old_contact = 0;
			}
			else
			{
				book.contacts[book.nb_contact].fill_info();
				if (book.contacts[book.nb_contact].empty_field())
					book.nb_contact++;
			}
		}
		else if (command == "SEARCH")
			book.print_contact();
		else if (command == "EXIT")
			return (0);
		else
			std::cout << "command INVALID"<< std::endl;
	}

	return 0;
}
