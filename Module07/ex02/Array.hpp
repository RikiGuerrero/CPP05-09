#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>


template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	
	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		Array(const Array &other) : _array(NULL), _size(other._size)
		{
			if (_size > 0)
			{
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = (_size > 0) ? new T[_size] : NULL;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return *this;
		}

		~Array()
		{
			delete[] _array;
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _array[i];
		}

		const T &operator[](unsigned int i) const
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _array[i];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif