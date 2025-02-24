#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_signed;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &form);
	virtual ~AForm();

	AForm 				&operator=(const AForm &form);

	std::string			getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat &bureaucrat);
	
	virtual void		execute(Bureaucrat const &executor) const = 0;

	// Exceptions
	class				FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class				GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class				GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class				FormAlreadySignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif