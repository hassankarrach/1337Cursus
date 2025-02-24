#include "./Array.hpp"

int main()
{
	try
	{
		Array<int> arr(5);

		arr[0] = -199;

		std::cout << arr[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}