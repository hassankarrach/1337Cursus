#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "iostream"
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *_elements;
	unsigned int _elements_size;

public:
	Array() : _elements(NULL), _elements_size(0)
	{
	}

	Array(unsigned int n) : _elements_size(n)
	{
		_elements = new T[n](); // () to initialize all ell to def value.
	}

	Array(Array &other) : _elements_size(other._elements_size)
	{
		this->_elements = new T[_elements_size];
		for (int i = 0; i < _elements_size; i++)
			this->_elements[i] = other._elements[i];
	}

	Array &operator=(Array &other)
	{
		if (this == &other)
			return (*this);

		delete [] _elements;

		_elements_size = other.size();
		_elements = new T[_elements_size];

		for (int i = 0; i < _elements_size; i++)
			_elements[i] = other._elements[i];

		return (*this);
	}

	T &operator[](unsigned int index)
	{
		if (index >= _elements_size)
			throw std::out_of_range("Index out of bounds!");
		return _elements[index];
	}

	unsigned int size(void) const
	{
		return this->_elements_size;
	};

	~Array()
	{
		delete[] _elements;
	}
};

#endif