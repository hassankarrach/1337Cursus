#include "./includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	_type = wrongCat._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
