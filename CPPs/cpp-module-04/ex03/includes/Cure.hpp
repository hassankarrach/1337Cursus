#ifndef	CURE_HPP
# define	CURE_HPP

# include "./AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure( void );
	Cure( const Cure &other );

	Cure	&operator=( const Cure &other );

	AMateria	*clone( void ) const;
	void		use( ICharacter &target );

	~Cure();
};

#endif