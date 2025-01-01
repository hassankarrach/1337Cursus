#include "./includes/Cure.hpp"
#include "./includes/Ice.hpp"
#include "./includes/Character.hpp"
#include "./includes/MateriaSource.hpp"

int	main( void )
{
	// Create a Spellbook 
	IMateriaSource	*spellbook = new MateriaSource();

	// Learn Spells == Add Spells to Spellbook
	spellbook->learnMateria(new Ice());
	spellbook->learnMateria(new Ice());
	spellbook->learnMateria(new Ice());
	spellbook->learnMateria(new Cure());

	// Create a Characters From Spellbook story
	ICharacter	*Sorcerer = new Character("Sorcerer");
	ICharacter	*Warrior = new Character("Warrior");

	Sorcerer->use(0, *Warrior);

	// Equip Spells to Characters

	Sorcerer->equip(spellbook->createMateria("ice"));
	Sorcerer->equip(spellbook->createMateria("cure"));

	Sorcerer->use(0, *Warrior);
	Sorcerer->use(1, *Warrior);

	// Unequip Spells from Characters
	Sorcerer->unequip(0);
	// Then
	Sorcerer->use(0, *Warrior); // Should not work

	// Deletes
	delete Sorcerer;
	delete Warrior;
	delete spellbook;
}