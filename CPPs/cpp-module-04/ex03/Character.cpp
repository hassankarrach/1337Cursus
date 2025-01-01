#include "./includes/Character.hpp"

t_unequiped_materials* Character::_unequiped_materials = NULL;

Character::Character( void )
{
	int	i = 0;

	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	this->_name = "Undefined";
}

Character::Character( std::string name )
{
	int	i = 0;

	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	this->_name = name;
}

Character::Character( const Character &c )
{
	int	i = 0;

	while (i < 4)
	{
		this->_inventory[i] = NULL;
		if (c._inventory[i] != NULL)
			this->_inventory[i] = c._inventory[i]->clone();
		i++;
	}
	this->_name = c._name;
}

Character	&Character::operator=( const Character &c )
{
	if (this != &c)
	{
		int	i = 0;

		while (i < 4)
		{
			if (this->_inventory[i] != NULL)
				delete(this->_inventory[i]);
			this->_inventory[i] = NULL;
			if (c._inventory[i] != NULL)
				this->_inventory[i] = c._inventory[i]->clone();
			i++;
		}
		this->_name = c._name;
	}
	return (*this);
}

std::string	const	&Character::getName( void )
{
	return (this->_name);
}

void	Character::equip( AMateria	*m )
{
	int	i = 0;

	while (i < 4)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break ;
		}
		i++;
	}
}

void	Character::unequip( int	idx )
{
	if (idx < 4 && idx >= 0 && this->_inventory[idx] != NULL)
	{
		this->addUnequipedMaterial(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
}

void	Character::use( int idx, ICharacter	&target )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}

Character::~Character()
{
	int	i = 0;

	while (i < 4)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
		i++;
	}
	t_unequiped_materials	*tmp;
	while (this->_unequiped_materials != NULL)
	{
		tmp = this->_unequiped_materials;
		this->_unequiped_materials = this->_unequiped_materials->next;
		delete (tmp->materials);
		delete (tmp);
	}
}

void Character::addUnequipedMaterial( AMateria *m )
{
	t_unequiped_materials	*new_material = new t_unequiped_materials;

	new_material->materials = m;
	new_material->next = this->_unequiped_materials;
	this->_unequiped_materials = new_material;
}