#include "./includes/Animal.hpp"
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"
#include "./includes/WrongAnimal.hpp"
#include "./includes/WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();


	// ===========================================
	std::cout << "=====================" << std::endl;


	const WrongAnimal *metaWrong = new WrongAnimal();
	const WrongAnimal *jWrong = new WrongCat();

	std::cout << jWrong->getType() << " " << std::endl;

	jWrong->makeSound();
	metaWrong->makeSound();

	

	// ===========================================
	delete meta;
	delete j;
	delete i;
	delete metaWrong;
	delete jWrong;
}