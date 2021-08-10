#include "span.hpp"

span::span()
{
	
}

span::~span()
{

}

span::span(span const& origin)
{
	*this = origin;
}

span& span::operator=(span const& origin)
{
	this->value = origin.value;
	return (*this);
}

