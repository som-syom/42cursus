#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat som1("som1", 10);
	Bureaucrat som("som", 1);
	Bureaucrat dhyeon("dhyeon", 150);

	std::cout << som << dhyeon;

	try
	{
		Bureaucrat dhyeon2("dhyeon2", -1);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------[" << som1.getName() << " increase grade test]" << std::endl;
		std::cout << som1;
		som1.incrementGrade();
		std::cout << som1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------[" << som.getName() << " increase grade test]" << std::endl;
		std::cout << som;
		som.incrementGrade();
		std::cout << som;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------[" << som1.getName() << " decrease grade test]" << std::endl;
		std::cout << som1;
		som1.decrementGrade();
		std::cout << som1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------[" << dhyeon.getName() <<" decrease grade test]" << std::endl;
		std::cout << dhyeon;
		dhyeon.decrementGrade();
		std::cout << dhyeon;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}