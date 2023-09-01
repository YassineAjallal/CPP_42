/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:10:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 01:41:36 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void test_orthodox()
{
	Span sp(5);
	for (int i = 0; i < 5; i++)
		sp.addNumber(i * 2);
	Span copy(sp);
	Span assign;
	assign = sp;
	std::cout << "shortest Span" << std::endl;
	std::cout << "sp :" << sp.shortestSpan() <<  "\tcopy :" << copy.shortestSpan() << "\tassign :" << assign.shortestSpan() << std::endl;
	std::cout << "longest Span" << std::endl;
	std::cout << "sp :" << sp.longestSpan() <<  "\tcopy :" << copy.longestSpan() << "\tassign :" << assign.longestSpan() << std::endl;
}

void test_span()
{
	Span sp = Span(9);
	std::vector<int> vect;
	for (int i = 0; i < 5; i++)
		vect.push_back(i * 20);
	try
	{
		for (int i = 0; i < 4; i++)
			sp.addNumber(i);
		sp.addMultipleNumber(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void test_span_full()
{
	Span sp = Span(9);
	try
	{
		for (int i = 0; i < 10; i++)
			sp.addNumber(i);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void test_no_span()
{
	Span sp = Span(9);
	std::vector<int> vect;
	try
	{
		for (int i = 0; i < 1; i++)
			sp.addNumber(i);
		sp.addMultipleNumber(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	std::cout << "___________________________ORTHODOX___________________________\n" << std::endl;
	test_orthodox();
	std::cout << "___________________________TEST SPAN___________________________\n" << std::endl;
	test_span();
	std::cout << "___________________________NO SPAN___________________________\n" << std::endl;
	test_no_span();
	std::cout << "___________________________FULL SPAN___________________________\n" << std::endl;
	test_span_full();
	return 0;
}
