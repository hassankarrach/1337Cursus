#include "Fixed.hpp"

int main()
{
	Fixed a(5);
	Fixed b(2);

	// ==== comparison operators ========>
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << (a < b ? "a is less than b" : "a is not less than b") << std::endl;
	std::cout << (a <= b ? "a is less than or equal to b" : "a is not less than or equal to b") << std::endl;
	std::cout << (a > b ? "a is greater than b" : "a is not greater than b") << std::endl;
	std::cout << (a >= b ? "a is greater than or equal to b" : "a is not greater than or equal to b") << std::endl;
	std::cout << (a == b ? "a is equal to b" : "a is not equal to b") << std::endl;
	std::cout << (a != b ? "a is not equal to b" : "a is equal to b") << std::endl;

	// ==== arithmetic operators ========>
	std::cout << "======================" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	// ==== inc/dec operators ===========>
	std::cout << "======================" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;

	return 0;
}