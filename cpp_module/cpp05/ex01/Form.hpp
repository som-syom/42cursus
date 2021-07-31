#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		int const			_sign_grade;
		int const			_exec_grade;
		bool				_signed;
		void	checkGrade(int sign, int exec);

		Form();
	public:
		Form(std::string const& name, int sign, int exec);
		virtual ~Form();
		Form(Form const&);
		Form& operator=(Form const&);
		
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat&);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, Form& b);

#endif
