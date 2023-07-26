/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:20:59 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 09:25:52 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>
class WrongAnimal {

protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& copy);
	std::string getType() const;
	void makeSound() const;
	~WrongAnimal();
};
#endif