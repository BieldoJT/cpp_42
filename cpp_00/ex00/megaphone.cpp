#include <iostream>
#include <ctype.h>

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		for(int i = 1;i < argc == 1;i++)
		{
			for(int j = 0; argv[i][j]; j++)
			{
				char c = toupper(argv[i][j]);
				std::cout << c;
			}
			if (argv[i + 1])
				std::cout << " ";
			else
				std::cout << std::endl;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	return 0;
}
