#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
	if (!array || !f)
		return;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif