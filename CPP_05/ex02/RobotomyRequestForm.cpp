/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:51:39 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/08 17:43:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("Default_target")
{
    std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "\e[0;33mParameterized Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequest", copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
    this->_target = assign.getTarget();
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void		 RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw BureaucratIsNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw ExecGradeIsNotCompatibleException();
	else
	{
		std::cout << "waiting..." << std::endl;
		if (std::time(NULL) % 2 == 0)
			std::cout << this->_target << "has been robotomized successfuly." << std::endl;
		else
			std::cout << "the robotomy failed." << std::endl;
	}
}

const char*  RobotomyRequestForm::ExecGradeIsNotCompatibleException::what() const throw()
{
	return ("Exec grade is not compatible");
}

const char*  RobotomyRequestForm::BureaucratIsNotSignedException::what() const throw()
{
	return ("Bureaucrat is not signed");
}
