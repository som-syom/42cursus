#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>

int main(void)
{
	std::cout << "--------------------------[string]" << std::endl;

	std::string test1 = "abcdefghijk";

	try
	{
		std::string::iterator iter;
		iter = easyfind(test1, 'd');
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::string::iterator iter;
		iter = easyfind(test1, 'z');
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------------------[vector]" << std::endl;

	std::vector<int> test2;
	for (int i = 1; i < 10; i += 2)
		test2.push_back(i);
	
	try
	{
		std::vector<int>::iterator iter2;
		iter2 = easyfind(test2, 5);
		std::cout << *iter2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int>::iterator iter2;
		iter2 = easyfind(test2, 4);
		std::cout << *iter2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "--------------------------[set]" << std::endl;

	std::set<int> test3;
	for (int i = 0; i < 10; i += 2)
		test3.insert(i);
	
	try
	{
		std::set<int>::iterator iter3;
		iter3 = easyfind(test3, 4);
		std::cout << *iter3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::set<int>::iterator iter3;
		iter3 = easyfind(test3, 5);
		std::cout << *iter3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------------------[multiset]" << std::endl;

	std::multiset<int> test4;
	for (int i = 0; i < 5; i++)
		test4.insert(i * 12);
	
	try
	{
		std::multiset<int>::iterator iter4;
		iter4 = easyfind(test4, 36);
		std::cout << *iter4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::multiset<int>::iterator iter4;
		iter4 = easyfind(test4, 99);
		std::cout << *iter4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------------------[list]" << std::endl;

	std::list<int> test5;
	for (int i = 0; i < 5; i++)
		test5.push_back(i * 11);
	
	try
	{
		std::list<int>::iterator iter;
		iter = easyfind(test5, 44);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator iter;
		iter = easyfind(test5, 12);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}