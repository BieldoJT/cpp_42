#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &other);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



#endif
