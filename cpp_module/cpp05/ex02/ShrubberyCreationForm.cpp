#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("none", 150, 150)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: Form("Shrubbery Creation", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& origin)
	: Form(origin), _target(origin._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& origin)
{
	Form::operator=(origin);
	this->_target = origin._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::ofstream f;

	Form::checkExecute(executor);
	f.open(_target + "_shrubbery", std::fstream::out);
	if (!f.is_open())
		throw ShrubberyCreationForm::FileOpenFailException();
	f << "   *    *  ()   *   *" << std::endl;
	f << "*        * /\\         *" << std::endl;
	f << "      *   /i\\\\    *  *" << std::endl;
	f << "    *     o/\\\\  *      *" << std::endl;
	f << " *       ///\\i\\    *" << std::endl;
	f << "     *   /*/o\\\\  *    *" << std::endl;
	f << "   *    /i//\\*\\      *" << std::endl;
	f << "        /o/*\\\\i\\   *" << std::endl;
	f << "  *    //i//o\\\\\\\\     *" << std::endl;
	f << "    * /*////\\\\\\\\i\\*" << std::endl;
	f << " *    //o//i\\\\*\\\\\\   *" << std::endl;
	f << "   * /i///*/\\\\\\\\\\o\\   *" << std::endl;
	f << "  *    *   ||     *    *" << std::endl;
	f.close();
}

const char* ShrubberyCreationForm::FileOpenFailException::what() const throw()
{
	return "!! File Open Fail !!";
}

