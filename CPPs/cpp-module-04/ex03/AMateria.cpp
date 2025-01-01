#include "./includes/AMateria.hpp"

AMateria::AMateria( void ): _type("undefined")
{
}

AMateria::AMateria( std::string	&type ): _type(type)
{
}

AMateria::AMateria( const AMateria &other ): _type(other._type)
{
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator=( const AMateria &other )
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const	&AMateria::getType( void ) const
{
	return (this->_type);
}

void	AMateria::use( ICharacter &target)
{
	(void) target;
}
