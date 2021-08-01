#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat zzang("zzang", 1);
	Intern som;

	try
	{
		std::cout << "____________________________[Shrubbery Creation test]" << std::endl;
		Form* form1 = som.makeForm("Shrubbery Creation", "test1");
		std::cout << form1;
		zzang.signForm(*form1);
		zzang.executeForm(*form1);
		delete form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "____________________________[Robotomy Request test]" << std::endl;
		Form* form2 = som.makeForm("Robotomy Request", "test2");
		std::cout << *form2;
		zzang.signForm(*form2);
		zzang.executeForm(*form2);
		delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << "____________________________[President Pardon test]" << std::endl;
		Form* form3 = som.makeForm("President Pardon", "test3");
		std::cout << *form3;
		zzang.signForm(*form3);
		zzang.executeForm(*form3);
		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		std::cout << "____________________________[Not Found Name test]" << std::endl;
		Form* form4 = som.makeForm("dhyeon zzang", "test4");
		std::cout << *form4;
		zzang.signForm(*form4);
		zzang.executeForm(*form4);
		delete form4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	

	return (0);
}