#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T, typename Func>
void iter(T* array, const std::size_t& len, Func func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T, typename Func>
void iter(const T* array, std::size_t len, Func func) {
	for (std::size_t i = 0; i < len; ++i) {
		func(array[i]); // const T&
	}
}



#endif
