#include "./includes/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "🐾 Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "🐾 Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "🐾 Animal assignation operator called" << std::endl;
	_type = animal._type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "🐾 Animal makes a generic sound." << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

Animal::~Animal()
{
	std::cout << "🐾 Animal destructor called" << std::endl;
}