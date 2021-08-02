#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string const&, int);
		virtual ~Bureaucrat();
		Bureaucrat(Bureaucrat const&);
		Bureaucrat& operator=(Bureaucrat const&);

		std::string getName() const;
		int getGrade() const;
		void setGrade(int);
		void incrementGrade();
		void decrementGrade();
	
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
