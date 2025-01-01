#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
	
public:
	// Constructors
	Cat();
	Cat(const Cat &cat);

	// Operator overloads
	Cat &operator=(const Cat &cat);

	// Member functions
	void makeSound() const;
	Brain *getBrain() const;
	
	// Destructor
	~Cat();
};

#endif