/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:22:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 09:30:24 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void func()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Type : " << j->getType() << " " << std::endl;
	std::cout << "Type : " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// std::cout << "\n--------------- Test Wrong Animal -----------------\n" << std::endl;
	// const WrongAnimal* k = new WrongCat();
	// std::cout << "Type : " << k->getType() << " " << std::endl;
	// k->makeSound();

	delete i;
	delete j;
	// delete k;
	delete meta;
}

int main()
{
	func();
	return (0);
}