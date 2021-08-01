#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string const&);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const&);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const&);

		void execute(Bureaucrat const& executor) const;

		class FileOpenFailException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
