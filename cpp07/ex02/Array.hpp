#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T *_array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &src);
	~Array();

	Array<T> &operator=(const Array<T> &src);

	T &operator[](unsigned int i);

	unsigned int size() const;
};

#include "Array.tpp"

#endif