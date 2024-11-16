#include "Zombie.hpp"

Zombie::Zombie(std::string): name(name){};
Zombie::~Zombie(){
	std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) const{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}