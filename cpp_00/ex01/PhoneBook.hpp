#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include "Contact.hpp"
# include <iomanip>


class PhoneBook
{
	private:
		Contact _contacts[8];
		int _isfull;
		int _qtd;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add_contact(Contact contact);
		void display_contacts();
		void get_contact(int index);

};

#endif
