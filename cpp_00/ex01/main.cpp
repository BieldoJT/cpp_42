#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdlib.h>


int main(void)
{
	PhoneBook pb;


	while(1)
	{
		std::string input;
		std::cout << "Write the command:" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> input;
		if(input == "ADD")
		{
			std::cin.ignore();
			std::string list_input[5];
			int i = 0;
			std::cout << "Digit the first name: " << std::endl;
			std::getline(std::cin, list_input[i++]);
			std::cout << "Digit the last name: " << std::endl;
			std::getline(std::cin, list_input[i++]);
			std::cout << "Digit the nickname: " << std::endl;
			std::getline(std::cin, list_input[i++]);
			std::cout << "Digit the phone number: " << std::endl;
			std::getline(std::cin, list_input[i++]);
			std::cout << "Digit your darkest secret: " << std::endl;
			std::getline(std::cin, list_input[i]);

			for(int i = 0;i < 5;i++)
			{
				if(list_input[i].empty())
				{
					std::cout << "Não deve haver campos nulos" << std::endl;
					break;
				}
			}
			Contact new_concact(list_input);
			pb.add_contact(new_concact);
		}
		else if(input == "SEARCH")
		{
			std::cin.ignore();
			std::string input;
			pb.display_contacts();
			std::cout << "Digite o index de busca: ";
			std::getline(std::cin, input);
			pb.get_contact(6); //fAZER FUNÇÂO PRA CONVERTER std:sstring para int;
		}
	}

}
