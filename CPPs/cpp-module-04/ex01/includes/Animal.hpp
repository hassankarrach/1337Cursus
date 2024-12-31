#ifndef ANIMAL_H
#define ANIMAL_H

#include "iostream"

class Animal
{
protected:
	std::string _type;

public:
	// Constructors
	Animal();
	Animal(const Animal &animal);

	// Operator overloads
	Animal &operator=(const Animal &animal);

	// Member functions
	virtual void makeSound() const;
	std::string getType() const;

	// Destructor
	virtual ~Animal();
};

#endif