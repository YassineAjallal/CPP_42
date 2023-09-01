/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:51:53 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/08 17:45:14 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

		std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;

		class ExecGradeIsNotCompatibleException : public std::exception
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

#endif // RobotomyRequestForm_HPP