#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, size_t arr_len, void (*func)(T&))
{
	if (arr_len == 0 || !arr)
		return;
	for (size_t i = 0; i < arr_len; i++)
	{
		func(arr[i]);
	}
}


#endif