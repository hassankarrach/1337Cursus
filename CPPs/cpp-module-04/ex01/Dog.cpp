#include "./includes/Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(), _brain(new Brain())
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = dog._type;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	_type = dog._type;
	*_brain = *dog._brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}