/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:18:32 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/08 17:04:52 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	this->_target = "default_target";
    std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	this->_target = target;
    std::cout << "\e[0;33mParametrized Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreation", copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
    this->_target = assign.getTarget();
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw BureaucratIsNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw ExecGradeIsNotCompatibleException();
	else
	{
		std::ofstream outfile;
		std::string fileName;

		fileName = this->_target + "_shrubbery";
		outfile.open(fileName.c_str(), std::ios::out);
		if (!outfile.is_open())
			throw OpenFileException();
		outfile << "      /\\      \n     /\\*\\     \n    /\\O\\*\\    \n   /*/\\/\\/\\   \n  /\\O\\/\\*\\/\\  \n /\\*\\/\\*\\/\\/\\ \n/\\O\\/\\/*/\\/O/\\ \n      ||      \n      ||      \n      ||      \n";
		outfile.close();
	}
}

const char*  ShrubberyCreationForm::ExecGradeIsNotCompatibleException::what() const throw()
{
	 return("Exec grade is not compatible");
}

const char*  ShrubberyCreationForm::OpenFileException::what() const throw()
{
	 return("cannot open file");
}

const char*  ShrubberyCreationForm::BureaucratIsNotSignedException::what() const throw()
{
	 return("Bureaucrat is not signed");
}


