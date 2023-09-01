/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:43:55 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/06 15:19:42 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;
class Bureaucrat {
    public:
        Bureaucrat();
		Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat & operator=(const Bureaucrat &assign);
        ~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string			getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& f);


    private:
        const	std::string _name;
        int		_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // Bureaucrat_HPP
