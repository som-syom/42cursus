#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat som("som", 1);
	Bureaucrat som2("som2", 49);
	Bureaucrat dhyeon("dhyeon", 50);

	std::cout << som << som2 << dhyeon;

	Form form1("form1", 49, 50);
	Form form2("form2", 51, 50);
	Form form3("form3", 30, 50);

	std::cout << form1 << form2;

	try
	{
		std::cout << "____________________________[test 1]" << std::endl;
		std::cout << som << form1;
		som.signForm(form1);
		std::cout << som << form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "____________________________[test 2]" << std::endl;
		std::cout << dhyeon << form3;
		dhyeon.signForm(form3);
		std::cout << dhyeon << form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "____________________________[test 3]" << std::endl;
		std::cout << dhyeon << form2;
		dhyeon.signForm(form2);
		std::cout << dhyeon << form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Form form4("form4", 1, 1);
	Form form5("form5", 60, 60);

	try
	{
		std::cout << "____________________________[test 4]" << std::endl;
		std::cout << dhyeon << form4;
		form4.beSigned(dhyeon);
		std::cout << dhyeon << form4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "____________________________[test 5]" << std::endl;
		std::cout << dhyeon << form5;
		form5.beSigned(dhyeon);
		std::cout << dhyeon << form5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}