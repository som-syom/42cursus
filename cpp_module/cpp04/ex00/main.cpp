#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Som.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");
	Som dhyeon("dhyeon");

	std::cout << robert << jim << joe << dhyeon;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(dhyeon);

	return 0;
}