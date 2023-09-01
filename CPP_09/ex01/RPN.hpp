/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 06:55:33 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/24 01:16:13 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <sstream>
#include <cstdlib>

class RPN {
	public:
		RPN(const RPN &copy);
		RPN & operator=(const RPN &assign);
		static void rpn_calculator(std::string input);
		~RPN();

	private:
		RPN();
		static int calc_tow_numbers(int nb_one, int nb_two, std::string op);
		static int  parse_input(std::string input_string, std::deque<std::string> &string_deque);

};

#endif // RPN_HPP
