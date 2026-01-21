#ifndef ARRAY_HPP
# define ARRAY_HPP


# include <cstddef>
# include <exception>

template <typename T>
class Array
{
private:
	T*	_data;
	std::size_t	_size;

public:
	Array() : _data(NUll), _size(0) {}
	Array(unsigned int n) : _data(NULL), _size(n)
	{
		if(_size > 0)
		{
			_data = new T[_size];
		}
	}

	Array(const Array& copy) : _data(NULL), _size(0)
	{
		*this = copy;
	}

	Array& operator=(const Array& other)
	{
		if(this == &other)
			return *this;
		T* newData = NULL;
		if(other._size > 0)
		{
			newData = new T[other._size];
			for (std::size_t i = 0; i < other._size; ++i)
				newData[i] = other._data[i];
		}

		delete[] _data;
		_data = newData;
		_size = other._size;
		return *this;
	}

	~Array()
	{
		delete[] _data;
	}

};


#endif
