#ifndef EASYFINDE_HPP
# define EASYFIND_HPP

# include<algorithm>
# include<exception>
class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}

};

template <typename T>
typename T::iterator easyfind(T &list, int n)
{
	typename T::iterator index;

	index = std::find(list.begin(), list.end(), n);
	if (index == list.end())
		throw NotFoundExeption;
	return index;
}

#endif
