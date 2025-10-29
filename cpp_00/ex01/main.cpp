#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdlib.h>
#include <limits.h>
#include <sstream>


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
			int is_ok = 1;
			for(int i = 0;i < 5;i++)
			{
				if(list_input[i].empty())
				{
					std::cout << "Não deve haver campos nulos" << std::endl;
					is_ok = 0;
					break;
				}
			}
			if(is_ok)
			{
				Contact new_concact(list_input);
				pb.add_contact(new_concact);
			}
		}
		else if(input == "SEARCH")
		{
			std::string input;
			pb.display_contacts();
			std::cout << "Digite o index de busca: " << std::endl;
			//std::cin.getline(input, INT_MAX);
			std::cin.ignore();
			std::getline(std::cin, input);
			std::istringstream data(input);
			int number;
			if(data >> number)
				pb.get_contact(number);
			else
				std::cout << "Input invalido" << std::endl;
			std::cout << std::endl;
		}
		else if(input == "EXIT")
		{
			exit(0);
		}
		else
			std::cout << "Invalid input" << std::endl;
	}

}
