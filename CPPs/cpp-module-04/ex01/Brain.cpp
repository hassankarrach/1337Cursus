#include "./includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "🧠 Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "🧠 Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &assign)
{
	std::cout << "🧠 Brain assignation operator called" << std::endl;
	if (this == &assign)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = assign.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "🧠 Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}