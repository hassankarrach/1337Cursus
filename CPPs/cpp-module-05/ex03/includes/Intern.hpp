#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{

public:
	Intern();
	Intern(Intern &other);
	Intern &operator=(Intern &other);

	~Intern();

	// Statics
	static AForm* createShrubbery(const std::string& t);
    static AForm* createRobotomy(const std::string& t);
    static AForm* createPardon(const std::string& t);

	AForm *makeForm(std::string form_name, std::string form_target);
	class FormNotFoundException : std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif