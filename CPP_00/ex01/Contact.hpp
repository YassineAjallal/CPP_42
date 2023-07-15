/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:19:36 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/10 18:04:19 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define	CONTACTS_HPP

#include <iostream>
#include <string>

class Contact {

private:
	std::string	darkest_secret;
	std::string	phone_number;
public : 
	std::string first_name;
	std::string last_name;
	std::string	nickname;

	void fill_info();
	int empty_field();
	void print_info();
};

#endif