#include "./includes/Cure.hpp"

Cure::Cure( void )
{
	this->_type = "cure";
}

Cure::Cure( const Cure &other ) : AMateria( other )
{
	this->_type = other._type;
}

Cure	&Cure::operator=( const Cure &other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria	*Cure::clone( void ) const
{
	return (new Cure( *this ));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* " << GREEN << "heals " << RESET << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
}