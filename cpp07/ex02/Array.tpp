
#include <stdexcept>

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _rawArray(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _rawArray(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other._size;
	_rawArray = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_rawArray[i] = other._rawArray[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other){
		if (_rawArray)
			delete[] _rawArray;
		_size = other._size;
		_rawArray = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_rawArray[i] = other._rawArray[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _rawArray;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size)
		throw std::out_of_range("Array index out of range");
	return _rawArray[idx];
}