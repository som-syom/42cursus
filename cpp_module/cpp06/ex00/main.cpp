#include "Convert.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "argument num error" << std::endl;
		return (1);
	}

	Convert a(av[1]);
	a.printAll();
	
	return(0);
}