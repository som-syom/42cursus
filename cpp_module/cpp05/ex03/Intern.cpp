#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const& origin)
{
	*this = origin;
}

Intern& Intern::operator=(Intern const& origin)
{
	(void)origin;
	return (*this);
}

Form* CreateShrubberyCreationForm(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

Form* CreateRobotomyRequestForm(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

Form* CreatePresidentialPardonForm(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(std::string const& name, std::string const& target)
{
	t_forms forms[3] = {
		{"Shrubbery Creation", CreateShrubberyCreationForm},
		{"Robotomy Request", CreateRobotomyRequestForm},
		{"President Pardon", CreatePresidentialPardonForm}
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			std::cout << "Intern creates < " << forms[i].name << " >" << std::endl;
			return forms[i].func(target);
		}
	}
	std::cerr << "Intern fail to create < " << name << " > because ";
	throw FormNameNotFoundException();
	return (0);
}

const char* Intern::FormNameNotFoundException::what() const throw()
{
	return ("!! Form name was not found !!");
}
