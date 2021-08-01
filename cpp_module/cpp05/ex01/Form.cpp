#include "Form.hpp"

Form::Form()
	: _name("none"), _sign_grade(0), _exec_grade(0)
{

}

Form::Form(std::string const& name, int sign, int exec)
	: _name(name), _sign_grade(sign), _exec_grade(exec)
{
	checkGrade(sign, exec);
	this->_signed = false;
}

Form::~Form()
{

}

Form::Form(Form const& origin)
	: _name(origin._name), _sign_grade(origin._sign_grade), _exec_grade(origin._exec_grade), _signed(origin._signed)
{
	checkGrade(origin._sign_grade, origin._exec_grade);
}

Form& Form::operator=(Form const& origin)
{
	checkGrade(origin._sign_grade, origin._exec_grade);
	this->_signed = origin._signed;
	return (*this);
}

void	Form::checkGrade(int sign, int exec)
{
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Form& b)
{
	out << "* ======= [ Form ] ======= *" << std::endl;
	out << "     Form name : " << b.getName() << std::endl;
	out << "    exec grade : " << b.getExecGrade() << std::endl;
	out << "    sign grade : " << b.getSignGrade() << std::endl;
	out << "     is signed : ";
	if (b.getSigned() == true)
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	out << "* ------------------------ *" << std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "!! Grade is Too High !!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "!! Grade is Too Low !!";
}
