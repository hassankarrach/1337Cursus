#include "./includes/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}


AForm* Intern::createShrubbery(const std::string& t) { return new ShrubberyCreationForm(t); }
AForm* Intern::createRobotomy(const std::string& t) { return new RobotomyRequestForm(t); }
AForm* Intern::createPardon(const std::string& t) { return new PresidentialPardonForm(t); }


AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	struct Pair
	{
		std::string name;
		AForm *(*creator)(const std::string &);
	};

	static const Pair FormTypes[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPardon}
	};

	for (int i = 0; i < 3; i++)
	{
		if (FormTypes[i].name == form_name)
			return FormTypes[i].creator(form_target);
	}

	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form is not exist.";
}