#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm test1("test1");
	RobotomyRequestForm test2("test2");
	PresidentialPardonForm test3("test3");

	Bureaucrat som("som", 1);

	std::cout << som << test1 << test2 << test3;
	std::cout << std::endl;
	try
	{
		std::cout << "____________________________[Shrubbery Creation test]" << std::endl;
		som.signForm(test1);
		som.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "____________________________[Robotomy Request test]" << std::endl;
		som.signForm(test2);
		som.executeForm(test2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "____________________________[President Pardon test]" << std::endl;
		som.signForm(test3);
		som.executeForm(test3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	RobotomyRequestForm test4("test4");
	try
	{
		std::cout << "____________________________[unsigned Form test]" << std::endl;
		som.executeForm(test4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Bureaucrat som2("som2", 150);
	try
	{
		std::cout << "____________________________[execute level too low test]" << std::endl;
		som.signForm(test4);
		som2.executeForm(test4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	ShrubberyCreationForm test5("tree");
	try
	{
		std::cout << "____________________________[file open fail test]" << std::endl;
		som.signForm(test5);
		som.executeForm(test5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return (0);
}