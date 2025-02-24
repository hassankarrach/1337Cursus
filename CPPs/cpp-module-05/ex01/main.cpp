#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

int main()
{
	Bureaucrat B1("Moudir", 4);
	Form form("F1", 5, 2);

	B1.signForm(form);

	B1.signForm(form);

	
	// std::cout << std::endl;
	// std::cout << "=>" << std::endl;
	// std::cout << B1;
	// std::cout << "=>" << std::endl;
	// std::cout << form;
}