/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 01:33:43 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
#include <vector>
#include <iostream>
#include <list>


void orthodox_test()
{
	MutantStack<int> my_stack;
	for (int i = 0; i < 5; i++)
		my_stack.push(i);
	MutantStack<int> copy_stack(my_stack);
	MutantStack<int> assign_stack;
	assign_stack = my_stack;
	MutantStack<int>::iterator it;
	std::cout << "-----> copy stack content" << std::endl;
	for ( it = copy_stack.begin() ; it != copy_stack.end() ; ++it)
		std::cout << *it << std::endl;
	std::cout << "-----> assign stack content" << std::endl;
	MutantStack<int>::iterator ita;
	for ( ita = assign_stack.begin() ; ita != assign_stack.end() ; ++ita)
		std::cout << *ita << std::endl;
	std::cout << "my stack top : " << my_stack.top() << "\tcopy stack top : " << copy_stack.top() << "\tassign stack top : " << assign_stack.top() << std::endl;
	std::cout << "my stack size : " << my_stack.size() << "\tcopy stack size : " << copy_stack.size() << "\tassign stack size : " << assign_stack.size() << std::endl;
}

void compare_width_stack()
{
	MutantStack<int> my_stack;
	std::stack<int> original_stack;
	
	std::cout << "my stack empty : " << my_stack.empty() << "\toriginal stack empty : " << original_stack.empty() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		my_stack.push(i);
		original_stack.push(i);
	}
	std::cout << "-----> my_stack content" << std::endl;
	MutantStack<int>::iterator it;
	for ( it = my_stack.begin() ; it != my_stack.end() ; ++it)
		std::cout << *it << std::endl;
	
	std::cout << "my stack empty : " << my_stack.empty() << "\toriginal stack empty : " << original_stack.empty() << std::endl;
	std::cout << "my stack top : " << my_stack.top() << "\toriginal stack top : " << original_stack.top() << std::endl;
	std::cout << "my stack size : " << my_stack.size() << "\toriginal stack size : " << original_stack.size() << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "my stack top : " << my_stack.top() << "\toriginal stack top : " << original_stack.top() << std::endl;
	std::cout << "my stack size : " << my_stack.size() << "\toriginal stack size : " << original_stack.size() << std::endl;

	
	
}

void compare_width_list()
{
	MutantStack<int> my_stack;
	std::list<int> original_list;
	
	std::cout << "my stack empty : " << my_stack.empty() << "\toriginal list empty : " << original_list.empty() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		my_stack.push(i);
		original_list.push_back(i);
	}
	std::cout << "-----> my_stack content " << std::endl;
	MutantStack<int>::iterator it;
	for ( it = my_stack.begin() ; it != my_stack.end() ; ++it)
		std::cout << *it << std::endl;

	std::cout << "-----> original list content " << std::endl;
	std::list<int>::iterator its;
	for ( its = original_list.begin() ; its != original_list.end() ; ++its)
		std::cout << *its << std::endl;

	std::cout << "my stack empty : " << my_stack.empty() << "\toriginal list empty : " << original_list.empty() << std::endl;
	std::cout << "my stack size : " << my_stack.size() << "\toriginal list size : " << original_list.size() << std::endl;
	my_stack.pop();
	original_list.pop_back();
	std::cout << "my stack size : " << my_stack.size() << "\toriginal list size : " << original_list.size() << std::endl;
	
}

void compare_width_vector()
{
	MutantStack<int> my_stack;
	std::vector<int> original_vector;
	
	std::cout << "my stack empty : " << my_stack.empty() << "\toriginal vector empty : " << original_vector.empty() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		my_stack.push(i);
		original_vector.push_back(i);
	}
	std::cout << "-----> my_stack content " << std::endl;
	MutantStack<int>::iterator it;
	for ( it = my_stack.begin() ; it != my_stack.end() ; ++it)
		std::cout << *it << std::endl;

	std::cout << "-----> original vector content" << std::endl;
	std::vector<int>::iterator its;
	for ( its = original_vector.begin() ; its != original_vector.end() ; ++its)
		std::cout << *its << std::endl;

	std::cout << "my stack empty : " << my_stack.empty() << "\toriginal vector empty : " << original_vector.empty() << std::endl;
	std::cout << "my stack size : " << my_stack.size() << "\toriginal vector size : " << original_vector.size() << std::endl;
	my_stack.pop();
	original_vector.pop_back();
	std::cout << "my stack size : " << my_stack.size() << "\toriginal vector size : " << original_vector.size() << std::endl;
	
}

void intra_main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}


int main()
{

	std::cout << "___________________________ORTHODOX___________________________\n" << std::endl;
	orthodox_test();
	std::cout << "___________________________STACK___________________________\n" << std::endl;
	compare_width_stack();
	std::cout << "\n___________________________LIST___________________________\n" << std::endl;
	compare_width_list();
	std::cout << "\n___________________________VECTOR___________________________\n" << std::endl;
	compare_width_vector();
	std::cout << "\n\n___________________________INTRA MAIN___________________________\n" << std::endl;
	intra_main();
	return 0;
}
