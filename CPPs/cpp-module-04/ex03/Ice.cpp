#include "./includes/Ice.hpp"

Ice::Ice( void )
{
	this->AMateria::_type = "ice";
}

Ice::Ice( const Ice &other ) : AMateria( other )
{
	this->AMateria::_type = other._type;
}

Ice	&Ice::operator=( const Ice &other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria	*Ice::clone( void ) const
{
	return (new Ice( *this ));
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an "<< BLUE << "ice bolt" << RESET << " at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
}