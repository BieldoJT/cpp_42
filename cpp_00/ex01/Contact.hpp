#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
class Contact
{
	public:
		Contact(void);
		Contact(std::string *list_input);
		~Contact();

		std::string get_first_name();
		std::string get_last_name();
		std::string get_nick_name();
		std::string get_phone_number();
		std::string get_darkest_secret();

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

};
#endif
