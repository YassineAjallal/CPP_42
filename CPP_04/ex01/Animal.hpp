/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:35:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:35:53 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
class Animal {

protected:
	std::string _type;
public:
	Animal();
	Animal(Animal& copy);
	Animal& operator=(const Animal& copy);
	std::string getType() const;
	virtual void makeSound() const;
	virtual ~Animal();
};

#endif