/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/17 10:14:50 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace(std::string& file_content, std::string s1, std::string s2)
{
	std::string new_content;
	size_t find_pos;

	find_pos = file_content.find(s1);
	while(find_pos < file_content.length())
	{
		file_content.erase(find_pos, s1.length());
		file_content.insert(find_pos, s2);
		find_pos = file_content.find(s1);
	}
}

int main(int ac, char **av)
{
	std::ifstream file;
	std::ofstream replace_file;
	std::string s1;
	std::string s2;
	std::string freplace_name;
	std::string file_content;

	if (ac != 4)
		std::cout << "Error : Bad Usage" << std::endl;
	else
	{
		freplace_name = av[1];
		freplace_name += ".replace";
		s1 = av[2];
		s2 = av[3];
		file.open(av[1], std::ios::in);
		if (file.is_open())
		{
			replace_file.open(freplace_name, std::ios::out);
			if(!replace_file.is_open())
			{
				file.close();
				std::cout << "Error : cannot open replace file" << std::endl;
				return (0);
			}
			while (getline(file, file_content))
			{
				replace(file_content, s1, s2);
				replace_file << file_content;
				if (!file.eof())
					replace_file << "\n";
			}
			file.close();
			replace_file.close();
		}
		else
			std::cout << "Error : cannot open file" << std::endl;
	}
	return (0);
}
