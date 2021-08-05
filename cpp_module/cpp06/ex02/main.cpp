#include "Base.hpp"

int main(void)
{
	srand(time(NULL));
	Base* test = generate();

	identify(test);
	delete test;

	Base* test2 = generate();
	identify(*test2);
	delete test2;

	return (0);
}