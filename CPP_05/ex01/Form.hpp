#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form {
public:

    Form();
	Form(std::string name, const int gradeSign, const int gradeExec);
    Form(const Form &copy);
    Form & operator=(const Form &assign);
    ~Form();

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	void		beSigned(const Bureaucrat& b);


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

private:
    const std::string	_name;
    bool				_isSigned;
    const int			_gradeSign;
    const int			_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const Form& b);
#endif // Form_HPP
