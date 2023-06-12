/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/06/12 19:31:28 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::fstream file;
	std::fstream replace_file;
	std::string s1;
	std::string s2;
	std::string freplace_name;
	std::string file_content;
	int i;
	if (ac != 4)
		std::cout << "Error : Bad Usage" << std::endl;
	else
	{
		int i;

		i = 0;
		freplace_name.assign(av[1]) += ".replace";
		s1.assign(av[2]);
		s2.assign(av[3]);
		file.open(av[1], std::ios::in);
		replace_file.open(freplace_name, std::ios::out);
		if (file.is_open() && replace_file.is_open())
		{
			while (getline(file, file_content))
			{
				i = 0;
				
				while(file_content[i])
				{
					if (file_content.find(s1, i) < file_content.length())
					{
						while (i < file_content.find(s1, i))
							replace_file << file_content[i++];
						replace_file << s2;
						i += s2.length();
					}
					else
						replace_file << file_content[i++];
				}
				replace_file << "\n";
			}
		}
		file.close();
		replace_file.close();
	}
	return (0);
}
