#include "./includes/Intern.hpp"
#include "./includes/AForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotddomy request", "Bender");


	std::cout << rrf->getName() << std::endl;
}