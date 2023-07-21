/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:46:53 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:41:27 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

private :
	Brain *_dog_brain;
public :
	Dog();
	Dog(Dog& copy);
	Dog& operator=(const Dog& copy);
	std::string getType() const;
	void setType(std::string type);
	void makeSound() const;
	~Dog();
};

#endif