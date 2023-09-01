/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:18:36 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/06 23:31:44 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
    // Constructors
    ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
	
	std::string	getTarget() const;
	void		execute(Bureaucrat const & executor) const;

	class ExecGradeIsNotCompatibleException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class OpenFileException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class BureaucratIsNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};

private:
	std::string _target;
};

#endif // ShrubberyCreationForm_HPP
