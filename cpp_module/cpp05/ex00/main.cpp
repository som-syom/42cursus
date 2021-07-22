#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat som("som", 1);
	Bureaucrat somsom("somsom", 10);
	Bureaucrat dhyeon("dhyeon", 150);

	std::cout << som << dhyeon;

	try
	{
		std::cout << "----------[somsom increase grade test]" << std::endl;
		std::cout << somsom;
		somsom.incrementGrade();
		std::cout << somsom;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------[som increase grade test]" << std::endl;
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
		std::cout << "----------[somsom decrease grade test]" << std::endl;
		std::cout << dhyeon;
		somsom.decrementGrade();
		std::cout << dhyeon;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------[dhyeon decrease grade test]" << std::endl;
		std::cout << dhyeon;
		dhyeon.decrementGrade();
		std::cout << dhyeon;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}