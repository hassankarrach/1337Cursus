#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
public:
	// Constructors
	Dog();
	Dog(const Dog &dog);

	// Operator overloads
	Dog &operator=(const Dog &dog);

	// Member functions
	void makeSound() const;
	
	// Destructor
	~Dog();
};

#endif