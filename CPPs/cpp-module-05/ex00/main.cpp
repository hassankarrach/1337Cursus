#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);

	try{
		b1.incrementGrade();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;

	try{
		b2.decrementGrade();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat b3("b3", 0);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}