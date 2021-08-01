#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("none", 150, 150)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: Form("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& origin)
	: Form(origin), _target(origin._target)
{
	*this = origin;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& origin)
{
	Form::operator=(origin);
	this->_target = origin._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	Form::checkExecute(executor);
	std::cout << "* drrrrrrrrrrrrrrrrr *" << std::endl;
	srand(time(NULL));
	if (std::rand() % 2)
		std::cout << "< " << this->_target << " > has been robotomized successfully" << std::endl;
	else
		std::cout << "< " << this->_target << " > failed to robotomized" << std::endl;
}
