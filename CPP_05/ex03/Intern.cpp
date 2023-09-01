/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:47:45 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/07 16:01:04 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors
Intern::Intern()
{
    std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}

// Destructor
Intern::~Intern()
{
    std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Operators
Intern & Intern::operator=(const Intern &assign)
{
    (void) assign;
    return *this;
}

AForm* Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*forms_creator[3])(std::string) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	for (i = 0; i < 3; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << "." << std::endl;
			return ((this->*forms_creator[i])(target));
		}
	}
	if (i == 3)
		std::cerr << "Form not found." << std::endl;
	return (NULL);
}
