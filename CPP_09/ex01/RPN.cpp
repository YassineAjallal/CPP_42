/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 06:16:01 by yajallal          #+#    #+#             */
/*   Updated: 2023/09/01 12:25:52 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
    (void) copy;
}

// Destructor
RPN::~RPN()
{
}

// Operators
RPN & RPN::operator=(const RPN &assign)
{
    (void) assign;
    return *this;
}

int RPN::calc_tow_numbers(int nb_one, int nb_two, std::string op)
{
	if (op == "-")
		return nb_one - nb_two;
	if (op == "+")
		return nb_one + nb_two;
	if (op == "*")
		return nb_one * nb_two;
	if (op == "/")
		return nb_one / nb_two;
	return (1);
}

int  RPN::parse_input(std::string input_string, std::deque<std::string> &string_deque)
{
	std::stringstream ss(input_string);
	size_t i;
	std::string line;
	while(!ss.eof())
	{
		std::getline(ss, line, ' ');
		if (line.length() != 0)
			string_deque.push_back(line);
	}
	i = 0;
	while (i < string_deque.size())
	{
		if ((i == 0 || i == 1) && (string_deque[i].length() != 1 || !std::isdigit(string_deque[i].at(0))))
			return (0);
		else if (string_deque[i].length() != 1 || (!std::isdigit(string_deque[i].at(0)) && !std::strchr("+-/*", string_deque[i].at(0))))
			return (0);
		i++;
	}
	return (1);
}

void RPN::rpn_calculator(std::string input)
{
	int nb_one, nb_two;
	size_t i;
	std::deque<std::string> string_deque;
	std::deque<int> numbers_deque;
	if (!RPN::parse_input(input, string_deque))
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	i = 0;
	while (i < string_deque.size())
	{
		if (std::isdigit(string_deque[i].at(0)))
			numbers_deque.push_back(std::atoi(string_deque[i].c_str()));
		else if (std::strchr("+-/*", string_deque[i].at(0)))
		{
			if (numbers_deque.size() < 2 )
			{
				std::cout << "Error" << std::endl;
				return;
			}
			nb_two = numbers_deque.back();
			numbers_deque.pop_back();
			nb_one = numbers_deque.back();
			numbers_deque.pop_back();
			numbers_deque.push_back(RPN::calc_tow_numbers(nb_one, nb_two, string_deque[i]));
		}
		i++;
	}
	if (numbers_deque.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	std::cout << numbers_deque.back() << std::endl;
}