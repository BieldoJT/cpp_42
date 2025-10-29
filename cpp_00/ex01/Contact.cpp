#include <iostream>
#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(std::string *list_input)
{
	_first_name = list_input[0];
	_last_name = list_input[1];
	_nickname = list_input[2];
	_phone_number = list_input[3];
	_darkest_secret = list_input[4];
	std::cout << "Contact criado\n" << std::endl;
}

Contact::~Contact()
{
}

std::string Contact::get_first_name()
{
	return _first_name;
}

std::string Contact::get_last_name()
{
	return _last_name;
}

std::string Contact::get_nick_name()
{
	return _nickname;
}

std::string Contact::get_phone_number()
{
	return _phone_number;
}

std::string Contact::get_darkest_secret()
{
	return _darkest_secret;
}


