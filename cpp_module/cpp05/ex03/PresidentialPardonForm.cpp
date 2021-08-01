#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("none", 150, 150)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: Form("Presidential Pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& origin)
	: Form(origin), _target(origin._target)
{
	*this = origin;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& origin)
{
	Form::operator=(origin);
	this->_target = origin._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	Form::checkExecute(executor);
	std::cout << "< " << this->_target << " > has been pardoned by Zafod Beeblebrox." << std::endl;
}
