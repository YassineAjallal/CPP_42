/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:47:49 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/07 15:40:13 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern & operator=(const Intern &assign);
	AForm *createShrubberyCreationForm(std::string target);
	AForm *createRobotomyRequestForm(std::string target);
	AForm *createPresidentialPardonForm(std::string target);
	AForm *makeForm(std::string name, std::string target);
private:

};

#endif // Intern_HPP
