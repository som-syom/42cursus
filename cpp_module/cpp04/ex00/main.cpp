#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Som.hpp"

int main()
{
	std::cout << "--------------------[sorcerer born]" << std::endl;
	Sorcerer robert("Robert", "the Magnificent");

	std::cout << "--------------------[victim born]" << std::endl;
	Victim jim("Jimmy");
	Peon joe("Joe");
	Som dhyeon("dhyeon");

	std::cout << "--------------------[victim getPolymorphed]" << std::endl;
	dhyeon.getPolymorphed();

	std::cout << "--------------------[std::cout << ]" << std::endl;
	std::cout << robert << jim << joe << dhyeon;

	std::cout << "--------------------[sorcerer polymorph]" << std::endl;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(dhyeon);

	std::cout << "--------------------[end]" << std::endl;
	return 0;
}