#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	_qtd = 0;
	_isfull = 0;
	std::cout << "Phnebook criado" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phnebook destruido" << std::endl;
}

void PhoneBook::add_contact(Contact contact)
{

	int pos;
	pos = _qtd%8;
	_contacts[pos] = contact;
	_qtd++;
	if(_qtd > 8)
		_isfull = 1;

}

void PhoneBook::display_contacts(void)
{
	int qtd_contacts = 0;
	if (_qtd > 8)
		qtd_contacts = 8;
	else
		qtd_contacts = _qtd;
			std::cout << std::setw(10) << "index" << "|"
			<< std::setw(10) << "first name"  << "|"
			<< std::setw(10) << "last name" << "|"
			<< std::setw(10) << "nickname" << "|" <<  std::endl;
	int i = 0;
	while(i < qtd_contacts)
	{
		std::string args[3];
		args[0] = _contacts[i].get_first_name();
		args[1] = _contacts[i].get_last_name();
		args[2] = _contacts[i].get_nick_name();
		for(int j = 0;j < 3;j++)
		{
			if(args[j].size() > 9)
				args[j] = args[j].substr(0,9) + ".";
		}

		std::cout << std::setw(10) << i + 1  << "|"
		<< std::setw(10) << args[0]  << "|"
		<< std::setw(10) << args[1]  << "|"
		<< std::setw(10) << args[2] << "|" <<std::endl;
		i++;
	}
	std::cout << std::endl;
}

void PhoneBook::get_contact(int index)
{
	if(index > _qtd || index >= 8|| index < 0)
	{
		std::cout << "Digite um index válido" << std::endl;
		return ;
	}



}
