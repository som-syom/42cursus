#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		
	public:
		Intern();
		virtual ~Intern();
		Intern(Intern const&);
		Intern& operator=(Intern const&);

		Form* makeForm(std::string const&, std::string const&);

		class FormNameNotFoundException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

typedef struct s_forms
{
	std::string name;
	Form* (*func)(const std::string);
}				t_forms;

#endif
