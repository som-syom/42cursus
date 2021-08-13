#include "span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
{
	this->_size = N;
	if (static_cast<int>(N) < 0)
		throw Span::OutofRangeException();
}

Span::~Span()
{
	this->_numbers.clear();
}

Span::Span(Span const& origin)
{
	
}

Span& Span::operator=(Span const& origin)
{
	
}

void Span::addNumber(unsigned int num)
{
	
}

int Span::shortestSpan()
{
	
}

int Span::longestSpan()
{

}

