#include "./includes/AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &form) : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute), _signed(false)
{
}
AForm::~AForm() {}
AForm &AForm::operator=(const AForm &form)
{
	if (this == &form)
		return *this;
	_signed = form._signed;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}
bool AForm::getSigned() const
{
	return _signed;
}
int AForm::getGradeToSign() const
{
	return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AForm::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
	}
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " form, required grade : " << form.getGradeToSign() << " to Get Signed." << std::endl
		<< "and grade : " << form.getGradeToExecute() << " to get Executed." << std::endl
		<< "its status : " << (form.getSigned() ? "Signed." : "Not Signed Yet.") << std::endl;

	return out;
}
