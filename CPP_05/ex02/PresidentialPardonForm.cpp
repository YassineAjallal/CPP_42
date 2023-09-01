/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:30:31 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/08 16:58:39 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5)
{
	this->_target = "default_target";
    std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5)
{
	this->_target = target;
    std::cout << "\e[0;33mParametrized Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardon", copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
    this->_target = assign.getTarget();
    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw BureaucratIsNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw ExecGradeIsNotCompatibleException();
	else
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

const char*  PresidentialPardonForm::ExecGradeIsNotCompatibleException::what() const throw()
{
	return ("Exec grade is not compatible");
}
const char*  PresidentialPardonForm::BureaucratIsNotSignedException::what() const throw()
{
	return ("Bureaucrat is not signed");
}
