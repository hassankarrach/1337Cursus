#include "./includes/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), _target(form._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this == &form)
		return (*this);
	AForm::operator=(form);
	_target = form._target;
	return (*this);
}

std::string				PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void					PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}