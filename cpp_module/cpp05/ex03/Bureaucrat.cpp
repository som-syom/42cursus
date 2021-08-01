#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
{
	this->_name = name;
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const& origin)
{
	*this = origin;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& origin)
{
	this->_name = origin._name;
	this->setGrade(origin._grade);
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade != 1)
		(this->_grade)--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade != 150)
		(this->_grade)++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << "< " << this->getName() << " > signs < " << f.getName() << " >" << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "< " << this->getName() << " > cannot sign < " << f.getName() << " >";
		std::cerr << " because < " << e.what() << " >" << std::endl;
	}
	
}

void Bureaucrat::executeForm(Form const& form)
{
	try
	{
		form.execute(*this);
		std::cout << "< " << this->getName() << " > executes < " << form.getName() << " >" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "< " << this->getName() << " > failed to execute < " << form.getName() << " > because ";
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "!! Grade is Too High !!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "!! Grade is Too Low !!";
}

