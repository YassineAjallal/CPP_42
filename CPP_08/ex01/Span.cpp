/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 09:29:08 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/21 02:26:13 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span()
{
	this->_n = 0;
}
Span::Span(unsigned int N)
{
	this->_n = N;
}
Span::Span(const Span &copy)
{
	this->_n = copy.getN();
    this->_span = copy._span;
}

// Destructor
Span::~Span(){}

// Operators
Span & Span::operator=(const Span &assign)
{
    std::vector<int>::iterator it;
	this->_n = assign.getN();
    this->_span = assign._span;
    return (*this);
}

unsigned int Span::getN() const
{
	return (this->_n);
}

void Span::addNumber(int number)
{
	if (this->_span.size() < this->_n)
	{
		this->_span.push_back(number);
	}
	else
		throw SpanIsFullException();
}

int Span::shortestSpan()
{
	if (this->_span.size() <= 1)
		throw NoSpanException();
	std::vector<int> vect = this->_span;
	std::sort(vect.begin(), vect.end());
	std::vector<int>::iterator it;
	int shortest;
	shortest = vect.at(1) - vect.at(0);
	for (it = vect.begin(); it != vect.end() - 1; ++it)
	{
		if (*(it + 1) - *it <= shortest)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (this->_span.size() <= 1)
		throw NoSpanException();
	return (*std::max_element(this->_span.begin(), this->_span.end()) - *std::min_element(this->_span.begin(), this->_span.end()));
}

void Span::addMultipleNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_span.size() + std::distance(begin, end) > this->_n)
		throw SpanIsFullException();
	this->_span.insert(this->_span.end(), begin, end);
}

const char* Span::SpanIsFullException::what() const throw()
{
	return "span is FULL";
}
const char* Span::NoSpanException::what() const throw()
{
	return "no span can be found";
}