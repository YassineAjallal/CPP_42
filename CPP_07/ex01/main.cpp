/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:32:48 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/16 19:05:31 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void modify_print(int a)
{
	a += 1;
	std::cout << a << std::endl; 
}

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	std::cout << "------------------------------" << std::endl;
	iter( tab2, 5, print<Awesome> );
	std::cout << "------------------------------" << std::endl;
	iter(tab, 5, modify_print);

  return 0;
}
