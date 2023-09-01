#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("default_name"), _isSigned(0), _gradeSign(10), _gradeExec(10)
{
    std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}
AForm::AForm(std::string name, const int gradeSign, const int gradeExec) : _name(name), _isSigned(0), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign > 150 || _gradeExec > 150)
		throw AForm::GradeTooLowException();
	if (_gradeSign < 1 || _gradeExec < 1)
		throw AForm::GradeTooHighException();
    std::cout << "\e[0;33mParametrized Constructor called of AForm\e[0m" << std::endl;
}
AForm::AForm(const AForm &copy) : _name(copy.getName()), _isSigned(0), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec())
{
    (void) copy;
    std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

// Destructor
AForm::~AForm()
{
    std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}

// Operators
AForm & AForm::operator=(const AForm &assign)
{
    this->_isSigned = assign.getIsSigned();
    return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too HIGH";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too LOW";
}

std::string	AForm::getName() const
{
	return (this->_name);
}
bool		AForm::getIsSigned() const
{
	return (this->_isSigned);
}
int			AForm::getGradeSign() const
{
	return (this->_gradeSign);
}
int			AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void				AForm::beSigned(const Bureaucrat& b)
{
	
	if (b.getGrade() <= this->_gradeSign)
		this->_isSigned = 1;
	else
		throw AForm::GradeTooLowException();
	
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", AForm grade required to sign " << f.getGradeSign() << ", AForm grade required to execute " << f.getGradeExec() <<".";
    return (os);
}

