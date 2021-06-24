#include <iostream>
#include <fstream>
#include <string>

int		main(int argc, char **argv)
{
	std::ifstream	s1;
	std::ofstream	s2;
	std::string		line;
	std::size_t		it = 0, idx = 0;
	char			*buf = 0;
	int				size;

	if (argc != 4 || !std::strlen(argv[2]))
		return (1);
	s1.open(argv[1], std::fstream::in | std::fstream::ate);
	if (!s1.is_open())
	{
		std::cout << "open error" << std::endl;
		return (1);
	}
	s2.open(std::string(argv[1]) + ".replace", std::fstream::out);
	size = s1.tellg();
	buf = new char[size];
	s1.seekg(0);
	s1.read(buf, size);
	line = buf;
	while ((it = line.find(argv[2], idx)) != std::string::npos)
	{
		line.replace(it, std::strlen(argv[2]), argv[3]);
		idx = it + std::strlen(argv[3]);
	}
	s2 << line;
	delete[] buf;
	s1.close();
	s2.close();
	return (0);
}