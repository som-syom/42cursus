#include "Form.hpp"

Form::Form()
{
	
}

Form::~Form()
{

}

Form::Form(Form const& origin)
{
	*this = origin;
}

Form& Form::operator=(Form const& origin)
{
	this->value = origin.value;
	return (*this);
}

