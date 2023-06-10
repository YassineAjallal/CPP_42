/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/06/10 21:32:08 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::fstream file;
	std::string file_content;
	if (ac != 4)
		std::cout << "Error : Bad Usage" << std::endl;
	else
	{
		file.open(av[1], std::ios::in);
		if (file.is_open())
		{
			while (getline(file, file_content))
			{
				std::cout << file_content << std::endl;
			}
		}
	}
	return (0);
}