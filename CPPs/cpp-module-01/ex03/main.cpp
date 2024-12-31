#include "./includes/HumanA.hpp"
#include "./includes/HumanB.hpp"
#include "./includes/Weapon.hpp"

int main()
{
	// Guns
	Weapon Draganov("Draganov");
	Weapon AK47("AK47");
	Weapon Shotgun("Shotgun");
	Weapon Pistol("Pistol");

	// Humans with weapons
	HumanA John("John", Draganov);
	HumanA Bob("Bob", AK47);

	// Humans without weapons
	HumanB Alice("Alice");
	HumanB Eve("Eve");

	// Humans with weapons can attack
	John.attack();
	Bob.attack();

	// Humans without weapons can't attack
	Alice.attack();
	Eve.attack();

	// Humans without weapons can get weapons
	Alice.setWeapon(Shotgun);
	Eve.setWeapon(Pistol);

	// == they can attack now
	Alice.attack();
	Eve.attack();

	/*
		==== 42 Test Cases
		{
			Weapon club = Weapon("crude spiked club");
			HumanA bob("Bob", club);
			bob.attack();
			club.setType("some other type of club");
			bob.attack();
		}
		{
			Weapon club = Weapon("crude spiked club");
			HumanB jim("Jim");
			jim.setWeapon(club);
			jim.attack();
			club.setType("some other type of club");
			jim.attack();
		}
	*/
}