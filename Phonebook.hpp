#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include "Contact.hpp"


class PhoneBook
{
	private:
		Contact _contacts[8];
		int _isfull;
		int _index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
};

#endif
