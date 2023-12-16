/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:12:35 by hikaru            #+#    #+#             */
/*   Updated: 2023/12/16 14:23:08 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;
	
public:
	Array(): _array(new T[0]), _size(0) {};
	Array(unsigned int n): _array(new T[n]), _size(n) {};
	Array(Array const &src) { *this = src; }
	Array &operator=(Array const &rhs) {
		if (this != &rhs)
		{
			delete[] (_array);
			_size = rhs._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		}
		return *this;
	}
	~Array() { delete[] (_array); };
	
	T &operator[](unsigned int const &index) { if (index >= _size) throw OutOfRangeException(); return _array[index]; };
	// T &operator[](unsigned int const &index) const { if (index >= _size) throw OutOfRangeException(); return _array[index]; };
	
	unsigned int size() const { return _size; }
	
	class OutOfRangeException : public std::exception
	{
		public:
			virtual const char *what() const throw() { return "Index is out of range";};
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T>& src)
{
	for (unsigned int i = 0; i < src.size(); i++)
		os << src[i] << " ";
	return os;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T>& src)
{
	for (unsigned int i = 0; i < src.size(); i++)
		os << src[i] << " ";
	return os;
};