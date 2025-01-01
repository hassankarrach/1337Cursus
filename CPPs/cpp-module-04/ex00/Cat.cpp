#include "./includes/Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat assignation operator called" << std::endl;
	_type = cat._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}