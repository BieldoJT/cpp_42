#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T, typename Func>
void iter(T* array, const std::size_t& len,const Func func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}



#endif
