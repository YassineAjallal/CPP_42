/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:12:52 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/12 16:15:24 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base {
public:
    virtual ~Base();
private:

};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
#endif // Base_HPP
