#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "string.h"
#include "iostream"
#include "Form.hpp"

class Form;

class Bureaucrat{
	private :
		const std::string	_name;
		int					_grade;

	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		Bureaucrat			&operator=(const Bureaucrat &bureaucrat);

		std::string			getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm(Form& form);

		// Exceptions
		class GradeTooHighException :  std::exception {
			public :
				const char *what() const throw();
		};
		class GradeTooLowException :  std::exception {
			public :
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif