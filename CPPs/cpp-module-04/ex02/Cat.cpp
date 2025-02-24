#include "./includes/Cat.hpp"

Cat::Cat() : _brain(NULL)
{
	_type = "Cat";
	std::cout << "🐱 Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "🐱 Cat copy constructor called" << std::endl;
	if (this != &cat)
	{
		_type = cat._type;
		_brain = new Brain(*cat._brain); // Deep copy
	}
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "🐱 Cat assignation operator called" << std::endl;
	if (this == &cat)
		return *this;

	_type = cat._type;

	if (this->_brain)
		delete _brain;

	_brain = new Brain(*cat._brain); // Deep copy
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "🐱 Cat destructor called" << std::endl;
	delete _brain;
}