#include <iostream>
#include <fstream>
#include <string>

int		main(int argc, char **argv)
{
	std::fstream	s1;
	std::fstream	s2;
	std::string		name;
	std::string		line;

	(void)argc;
	(void)argv;
	// if (argc != 4)
	// 	return (0);
	s1.open(argv[1], std::fstream::in);
	name.append(argv[1]);
	name.append(".replace");
	s2.open(name, std::fstream::out);
	
	s1.close();
	s2.close();
}