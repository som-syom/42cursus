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

	public:
		Form();
		Form(std::string const& name, int sign, int exec);
		virtual ~Form();
		Form(Form const&);
		Form& operator=(Form const&);
		
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat&);

		void checkExecute(Bureaucrat const& executor) const;
		virtual void execute(Bureaucrat const& executor) const = 0;

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
		class UnsignedFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, Form& b);

#endif
