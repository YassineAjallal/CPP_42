/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:43:47 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/08 16:49:07 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("Default_name")
{
    this->_grade = 150;
    std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
    std::cout << "\e[0;33mParametrized Constructor called of Bureaucrat\e[0m" << std::endl;
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
    *this = copy;
    std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
    this->_grade = assign.getGrade();
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
        return "Grade is too HIGH";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
        return "Grade is too LOW";
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}
void	Bureaucrat::signForm(Form& f)
{
	try
	{
		
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}
