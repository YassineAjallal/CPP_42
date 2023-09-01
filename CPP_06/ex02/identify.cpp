/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:13:37 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 16:36:04 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
	time_t t = time(NULL) % 10;
	if (t >= 0 && t <= 3)
	{
		std::cout << "form generate : A" << std::endl;
		return (new A());
	}
	else if (t > 3 && t <= 6)
	{
		std::cout << "form generate : B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "form generate : C" << std::endl;
		return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p) != NULL)
		std::cout << "from identifyPtr : A" << std::endl;
	else if (dynamic_cast <B*> (p) != NULL)
		std::cout << "from identifyPtr : B" << std::endl;
	else
		std::cout << "from identifyPtr : C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		__unused Base& a = dynamic_cast <A&> (p);
		std::cout << "from identifyRef : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			__unused Base& b = dynamic_cast <B&> (p);
			std::cout << "from identifyRef : B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				__unused Base& c = dynamic_cast <C&> (p);
				std::cout << "from identifyRef : C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}