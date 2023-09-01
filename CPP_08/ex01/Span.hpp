/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 09:29:42 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 02:26:19 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();
		Span & operator=(const Span &assign);
		unsigned int getN() const;
		void addNumber(int number);
		void addMultipleNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int	shortestSpan();
		int longestSpan();
		class SpanIsFullException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public :
				const char* what() const throw();
		};
	private:
		std::vector<int> _span;
		unsigned int _n;
		
};

#endif // Span_HPP

