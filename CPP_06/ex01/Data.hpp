/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:23:23 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/10 23:26:58 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {
	public:
		Data();
		Data(std::string name);
		Data(const Data &copy);
		~Data();
		Data & operator=(const Data &assign);
		std::string getName() const;

	private:
		std::string _name;

};

#endif // Data_HPP
