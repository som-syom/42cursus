#include "span.hpp"

int main(void)
{
	std::cout << "-------------------------[int test]" << std::endl;
	Span test(5);

	test.addNumber(-2147483648);
	test.addNumber(3);
	test.addNumber(5);
	test.addNumber(7);
	test.addNumber(2147483647);

	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	std::cout << "-------------------------[container full test]" << std::endl;
	try
	{
		test.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-------------------------[rand num test]" << std::endl;
	Span test3(3);

	try
	{
		test3.addNumber(1);
		test3.addNumber(1);
		test3.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-------------------------[not enogh num test]" << std::endl;
	try
	{
		std::cout << test3.longestSpan() << std::endl;
		std::cout << test3.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-------------------------[out of range test]" << std::endl;
	try
	{
		Span test4(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << "-------------------------[rand num test]" << std::endl;
	srand(time(NULL));

	Span test2(10000);

	test2.addRandomNumber(10000);
	// test2.printAll();

	std::cout << test2.shortestSpan() << std::endl;
	std::cout << test2.longestSpan() << std::endl;

	return (0);
}