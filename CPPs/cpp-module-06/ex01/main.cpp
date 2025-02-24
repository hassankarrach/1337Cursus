#include "Serializer.hpp"

int	main(void)
{
	Data	testData;

	testData.a = 1;
	testData.test = "111";
    
	std::cout << "before Serialization	" << &testData << std::endl;
	std::cout << std::hex << "uintptr:		" << Serializer::serialize(&testData) << std::endl;
	std::cout << "after Serialization	" << Serializer::deserialize(Serializer::serialize(&testData)) << std::endl;
}