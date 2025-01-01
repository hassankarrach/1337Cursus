#ifndef	CHARACTER_HPP
# define CHARACTER_HPP

#include "./ICharacter.hpp"
#include "./AMateria.hpp"

typedef struct s_unequiped_materials
{
	AMateria						*materials;
	struct s_unequiped_materials	*next;
}									t_unequiped_materials;

class Character: public	ICharacter
{
private:
	AMateria						*_inventory[4];
	std::string						_name;
	static t_unequiped_materials	*_unequiped_materials;

public:
	Character( void );
	Character( const std::string name );
	Character( const Character &other );

	Character	&operator=( const Character &other );

	std::string	const	&getName( void );
	void				equip( AMateria	*m );
	void				unequip( int	idx );
	void				use( int idx, ICharacter	&target );
	void				addUnequipedMaterial( AMateria *m );
	
	virtual	~Character();
};


#endif