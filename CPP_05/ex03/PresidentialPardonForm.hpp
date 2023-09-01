/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:30:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/06 23:29:11 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp" 

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
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

#endif // PresidentialPardonForm_HPP
