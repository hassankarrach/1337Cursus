#ifndef	AMATERIA_HPP
# define AMATERIA_HPP

# include "./ICharacter.hpp"

// Colors Macros
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria( void );
	AMateria( std::string &type );
	AMateria( const AMateria &other );

	AMateria	&operator=( const AMateria &other );

	std::string const	&getType( void ) const;

	virtual	AMateria	*clone( void ) const = 0;
	
	virtual	void		use( ICharacter &target );

	virtual	~AMateria();
};

#endif