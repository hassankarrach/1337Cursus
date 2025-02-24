#include "./includes/Form.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
}
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form &form) : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute), _signed(false)
{
}
Form::~Form() {}
Form &Form::operator=(const Form &form)
{
	if (this == &form)
		return *this;
	_signed = form._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}
bool Form::getSigned() const
{
	return _signed;
}
int Form::getGradeToSign() const
{
	return _gradeToSign;
}
int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw Form::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
	}
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
const char *Form::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " form, required grade : " << form.getGradeToSign() << " to Get Signed." << std::endl
		<< "and grade : " << form.getGradeToExecute() << " to get Executed." << std::endl
		<< "its status : " << (form.getSigned() ? "Signed." : "Not Signed Yet.") << std::endl;

	return out;
}
