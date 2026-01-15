#include "Serializer.hpp"

int main(void)
{

	Data* data = new Data;
	data->msg = "Isso mudou?";
	data->name = "Gabriel";
	data->number = 26;

	std::cout << "Dados atuais: " << std::endl
	<< "msg: " << data->msg << std::endl
	<< "name: " << data->name << std::endl
	<< "number: " << data->number << std::endl << std::endl;

	uintptr_t number = Serializer::serialize(data);

	std::cout << "APOS SERIALIZAÇÂO: " << number << std::endl << std::endl;

	Data* newData = Serializer::deserialize(number);

	std::cout << "APOS A desSERIALIZAÇÂO" << std::endl
	<< "ANTES" << std::endl << std::endl
	<< "Dados antes: " << std::endl
	<< "msg: " << data->msg << std::endl
	<< "name: " << data->name << std::endl
	<< "number: " << data->number << std::endl << std::endl
	<< "Depois" << std::endl << std::endl
	<< "msg: " << newData->msg << std::endl
	<< "name: " << newData->name << std::endl
	<< "number: " << newData->number << std::endl;

	return 0;


}
