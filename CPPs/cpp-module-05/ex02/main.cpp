#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"

int main()
{
	// ======Forms ::
	ShrubberyCreationForm S_form("home");	  // 145 to sign, 137 to execute
	PresidentialPardonForm P_form("muwadaf"); // 25  to sign, 5   to execute
	RobotomyRequestForm R_form("lottery");	  // 72  to sign, 45  to execute

	Bureaucrat lmoudir("lmoudir", 5);

	std::cout << "==Simple task ==============> "<<std::endl;
	lmoudir.signForm(S_form);
	lmoudir.executeForm(S_form);

	std::cout << "==50% succed chance ========> "<<std::endl;
	lmoudir.signForm(R_form);
	lmoudir.executeForm(R_form);

	std::cout << "==high dec =================> "<<std::endl;
	lmoudir.signForm(P_form);
	lmoudir.executeForm(P_form);
}