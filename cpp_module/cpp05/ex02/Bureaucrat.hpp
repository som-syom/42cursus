#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string const&, int);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const&);
		Bureaucrat& operator=(Bureaucrat const&);

		std::string getName() const;
		int getGrade() const;
		void setGrade(int);
		void incrementGrade();
		void decrementGrade();

		void signForm(Form&);
		void executeForm(Form const& form);
	
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
