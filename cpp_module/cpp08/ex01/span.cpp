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
	this->_N = origin._N;
	this->_count = origin._count;
	this->_numbers = new int[this->_N];
	for (int i = 0; i < this->_count; i++)
		this->_numbers[i] = origin._numbers[i];
}

Span& Span::operator=(Span const& origin)
{
	if (!this->_numbers)
		delete[] this->_numbers;
	this->_N = origin._N;
	this->_count = origin._count;
	this->_numbers = new int[this->_N];
	for (int i = 0; i < this->_count; i++)
		this->_numbers[i] = origin._numbers[i];
	return (*this);
}

void Span::addNumber(unsigned int num)
{
	for (int i = 0; i < this->_count; i++)
	{
		if (this->_numbers[i] == num)
		{
			throw DuplicatedNumException();
			return ;
		}
	}
	this->_numbers[this->_count] = num;
	this->_count++;
}

int Span::shortestSpan()
{
	
}

int Span::longestSpan()
{

}

