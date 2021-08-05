#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data* test1 = new Data;

	test1->c = 'a';
	test1->i = 42;
	test1->s = "abcdefghijklmnopqrstuvwxyz4242";
	test1->d = 42.4242;

	std::cout << "test1 = " << test1 << std::endl;
	
	std::cout << "----- [Data* -> uintptr_t] -----" << std::endl;
	uintptr_t ptr1 = serialize(test1);
	std::cout << "ptr1  = " << ptr1 << std::endl;

	std::cout << "----- [uintptr_t -> Data*] -----" << std::endl;
	Data* test2 = deserialize(ptr1);
	std::cout << "test2 = " << test2 << std::endl;

	std::cout << "----- [Data* -> uintptr_t] -----" << std::endl;
	uintptr_t ptr2 = serialize(test2);
	std::cout << "ptr2  = " << ptr2 << std::endl;

	std::cout << "----- [test1, test2 data] -----" << std::endl;
	std::cout << "test1.c = " << test1->c << std::endl;
	std::cout << "test2.c = " << test2->c << std::endl;
	std::cout << "test1.i = " << test1->i << std::endl;
	std::cout << "test2.i = " << test2->i << std::endl;
	std::cout << "test1.s = " << test1->s << std::endl;
	std::cout << "test2.s = " << test2->s << std::endl;
	std::cout << "test1.d = " << test1->d << std::endl;
	std::cout << "test2.d = " << test2->d << std::endl;

	std::cout << "size test = " << sizeof(test1) << std::endl;
	std::cout << "size ptr  = " << sizeof(ptr1) << std::endl;

	ptrdiff_t p = ptr1 - ptr2;
	std::cout << p << std::endl;

}