#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct s_data
{
	int			a;
	std::string	test;
}	Data;

class	Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer	&operator=(const Serializer &copy);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif