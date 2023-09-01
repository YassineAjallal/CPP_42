#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
public:

    AForm();
	AForm(std::string name, const int gradeSign, const int gradeExec);
    AForm(const AForm &copy);
    AForm & operator=(const AForm &assign);
    ~AForm();

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	void		beSigned(const Bureaucrat& b);
	virtual void	execute(Bureaucrat const & executor) const = 0;


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

std::ostream& operator<<(std::ostream& os, const AForm& b);
#endif // Form_HPP
