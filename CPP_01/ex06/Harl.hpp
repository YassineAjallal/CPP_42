/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:56:31 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/14 19:57:50 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	
private :
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public :
	void complain(std::string level);
	void harlFilter(std::string level);
};

#endif