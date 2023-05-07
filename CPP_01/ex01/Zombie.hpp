/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:28:01 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/07 17:42:23 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie{

public :
	Zombie();
	Zombie( std::string name );
	~Zombie();
	void announce (void);

private:

	std::string _name;
};