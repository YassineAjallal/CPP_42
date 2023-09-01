/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:36:15 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/08 16:59:58 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
// Constructors
Form::Form() : _name("default_name"), _isSigned(0), _gradeSign(10), _gradeExec(10)
{
    std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}
Form::Form(std::string name, const int gradeSign, const int gradeExec) : _name(name), _isSigned(0), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign > 150 || _gradeExec > 150)
		throw Form::GradeTooLowException();
	if (_gradeSign < 1 || _gradeExec < 1)
		throw Form::GradeTooHighException();
    std::cout << "\e[0;33mParametrized Constructor called of Form\e[0m" << std::endl;
}
Form::Form(const Form &copy) : _name(copy.getName()), _isSigned(0), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec())
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
    std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign)
{
    this->_isSigned = assign.getIsSigned();
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW";
}

std::string	Form::getName() const
{
	return (this->_name);
}
bool		Form::getIsSigned() const
{
	return (this->_isSigned);
}
int			Form::getGradeSign() const
{
	return (this->_gradeSign);
}
int			Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void				Form::beSigned(const Bureaucrat& b)
{
	
	if (b.getGrade() <= this->_gradeSign)
		this->_isSigned = 1;
	else
		throw Form::GradeTooLowException();
	
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", grade required to sign " << f.getGradeSign() << ", grade required to execute " << f.getGradeExec() <<".";
    return (os);
}

