#include "./includes/Dog.hpp"

Dog::Dog() : _brain(NULL)
{
	_type = "Dog";
	std::cout << "🐶 Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "🐶 Dog copy constructor called" << std::endl;
	if (this != &dog)
	{
		_type = dog._type;
		_brain = new Brain(*dog._brain); // Deep copy
	}
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "🐶 Dog assignation operator called" << std::endl;
	if (this == &dog)
		return *this;

	_type = dog._type;

	if (this->_brain)
		delete _brain;

	_brain = new Brain(*dog._brain); // Deep copy
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
} 

Dog::~Dog()
{
	std::cout << "🐶 Dog destructor called" << std::endl;
	delete _brain;
}