#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
public:
	// Constructors
	Cat();
	Cat(const Cat &cat);

	// Operator overloads
	Cat &operator=(const Cat &cat);

	// Member functions
	void makeSound() const;
	
	// Destructor
	~Cat();
};

#endif