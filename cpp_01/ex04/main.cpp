#include <iostream>
#include <fstream>

std::string replace(std::string line, const std::string search, const std::string replace)
{
	size_t	erase_length = search.length();
	size_t	replace_length = replace.length();
	size_t	pos_search = 0;

	pos_search = line.find(search);
	while (pos_search != std::string::npos)
	{
		line.erase(pos_search, erase_length);
		line.insert(pos_search, replace);
		pos_search = line.find(search, pos_search + replace_length);
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	std::string filename = argv[1];
	std::string filename_out;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream archive_in;
	std::ofstream archive_out;

	archive_in.open(filename.c_str());
	filename_out = filename + ".replace";
	archive_out.open(filename_out.c_str());



	if(!archive_in.is_open())
	{
		archive_out.close();
		std::cerr << "Error to open the filename " << filename << std::endl;
		return 1;
	}
	if(!archive_out.is_open())
	{
		archive_in.close();
		std::cerr << "Error to open the filename " << filename_out << std::endl;
		return 1;
	}
	if(s1 == "" || s2 == "")
	{
		std::cerr << "s1 or s2 can't be empty string" << std::endl;
		return 1;
	}

	std::string line;
	while(std::getline(archive_in, line))
	{
		std::string new_line = replace(line, s1, s2);
		archive_out << new_line << std::endl;
	}
	archive_in.close();
	archive_out.close();
	return 0;
}
