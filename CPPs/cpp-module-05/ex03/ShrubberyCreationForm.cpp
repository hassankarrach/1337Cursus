#include "./includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("Shrubbery Creation Form", 145, 137), _target(name)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("Shrubbery Creation Form", 145, 137)
{
	(void)other;
}
std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream file;

	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}

	file.open((_target + "_shrubbery").c_str(), std::ios::out);
	if (file.is_open())
	{
		file << "       _\\/_\n";
		file << "        /\\\n";
		file << "       /  \\\n";
		file << "      /~~\\o\n";
		file << "     /o   \\\n";
		file << "    /~~*~~~\\\n";
		file << "   o/    o \\\n";
		file << "   /~~~~~~~~\\~`\n";
		file << "   /__*_______\\\n";
		file << "        ||\n";
		file << "      \\====/\n";
		file << "       \\__/\n";

		file.close();
	}
	else
		std::cerr << "Error: could not open file" << std::endl;
}