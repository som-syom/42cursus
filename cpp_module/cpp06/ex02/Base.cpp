#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Destructure of Base" << std::endl;
}

Base* generate(void)
{
	int a = rand() % 3;
	if (a == 0)
	{
		A *a = new A;
		return (dynamic_cast<Base*>(a));
	}
	else if (a == 1)
	{
		B *b = new B;
		return (dynamic_cast<Base*>(b));
	}
	else
	{
		C *c = new C;
		return (dynamic_cast<Base*>(c));
	}
}

void identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
	{
		(void)a;
		std::cout << "real type is A" << std::endl;
	}
	else if (B* b = dynamic_cast<B*>(p))
	{
		(void)b;
		std::cout << "real type is B" << std::endl;
	}
	else if (C* c = dynamic_cast<C*>(p))
	{
		(void)c;
		std::cout << "real type is C" << std::endl;
	}
	else
		std::cout << "type is invalid" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "real type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}

	try
	{
		B b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "real type is B" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}

	try
	{
		C c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "real type is C" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
}
