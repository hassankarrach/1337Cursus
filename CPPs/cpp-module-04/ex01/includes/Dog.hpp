#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
	
public:
	// Constructors
	Dog();
	Dog(const Dog &dog);

	// Operator overloads
	Dog &operator=(const Dog &dog);

	// Member functions
	void makeSound() const;
	Brain *getBrain() const;

	// Destructor
	~Dog();
};

#endif