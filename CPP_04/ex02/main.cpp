/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:22:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 10:07:31 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void func1()
{
	Animal *a[4];
	// Animal b;

	// Dog d1;
	// Cat c1;
	// Cat c2;

	// c2 = c1;
	a[0] = new Dog();
	a[1] = new Dog();
	a[2] = new Cat();
	a[3] = new Cat();
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