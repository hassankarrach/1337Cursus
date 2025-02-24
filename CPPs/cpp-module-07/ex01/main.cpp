#include "iter.hpp"


void inc(int &num)
{
	num++;
}

void inc_char(char &_char)
{
	_char++;
}

int main()
{
	char arr[3] = {'a', 'b', 'c'};

	iter(arr, 3, inc_char);

	std::cout << arr[0] << std::endl;
}