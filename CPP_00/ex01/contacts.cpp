/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:21:41 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/05 19:21:44 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

void aligned(std::string str)
{
	int i;
	int length;

	i = 0;
	length = str.length();
	if (length < 10)
	{
		while (i < 10 - length)
		{
			std::cout << " ";
			i++;
		}
		std::cout << str;
	}
	else if (length > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << str;

}


int main()
{
	PhoneBook book;
	std::string command;
	book.nb_contact = 0;
	book.old_contact = 0;


		while (1)
		{
			std::cout << "\e[1;32mEnter a command (ADD, SEARCH, EXIT) : \e[0;00m";
			std::cin >> command;
			if (command == "ADD")
			{
				if (book.nb_contact > 2)
				{
					book.contacts[book.old_contact].fill_info();
					book.old_contact++;
					if (book.old_contact > 2)
						book.old_contact = 0;
				}
				else
				{
					book.contacts[book.nb_contact].fill_info();
					book.nb_contact++;
				}
			}
			else if (command == "SEARCH")
			{
				book.print_contact();
			}
			else if (command == "EXIT")
				return (0);
			else
				std::cout << "The command is INVALID"<< std::endl;
		}

	return 0;
}

