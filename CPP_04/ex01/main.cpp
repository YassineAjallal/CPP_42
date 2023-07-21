/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:22:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 12:42:43 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void func1()
{
	Animal *a[4];

	a[0] = new Dog;
	a[1] = new Dog;
	a[2] = new Cat;
	a[3] = new Cat;
	std::cout << "--------------------------\n" << std::endl;
	for(int i = 0; i < 4; i++)
		delete a[i];
}
int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;	//should not create a leak
	// delete i;
	func1();
	return 0;
}