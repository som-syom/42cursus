#include "span.hpp"
#include <cstdlib>

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
	*this = origin;
}

Span& Span::operator=(Span const& origin)
{
	this->_numbers.clear();
	this->_size = origin._size;
	this->_numbers = std::set<int>(origin._numbers);
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->_numbers.size() == this->_size)
		throw Span::FullContainerException();
	else if (this->_numbers.find(num) != this->_numbers.end())
		throw Span::DuplicatedNumException();
	else
		this->_numbers.insert(num);
}

void Span::addRandomNumber(unsigned int size)
{
	if (this->_numbers.size() + size > this->_size)
		throw Span::FullContainerException();
	else
	{
		for (unsigned int i = 0; i < size; i++)
		{
			int rand_num = rand();
			if (this->_numbers.find(rand_num) != this->_numbers.end())
				i--;
			else
				this->_numbers.insert(rand_num);
		}
	}
}

void Span::printAll()
{
	std::set<int>::iterator iter = this->_numbers.begin();
	for (; iter != this->_numbers.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

long long Span::shortestSpan()
{
	if (this->_numbers.size() == 1 || this->_numbers.empty() == true)
		throw Span::NotEnoghNumException();
	std::set<int>::iterator iter1 = this->_numbers.begin();
	std::set<int>::iterator iter2 = this->_numbers.begin();
	iter2++;
	long long shortest;
	for (; iter2 != this->_numbers.end(); ++iter1, ++iter2)
	{
		long long diff = (long long)*iter2 - (long long)*iter1;
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

long long Span::longestSpan()
{
	if (this->_numbers.size() == 1 || this->_numbers.empty() == true)
		throw Span::NotEnoghNumException();
	long long longest = (long long)*this->_numbers.rbegin()
					- (long long)*this->_numbers.begin();
	return (longest); 
}

const char* Span::OutofRangeException::what() const throw()
{
	return ("!! Out of Range !!");
}

const char* Span::DuplicatedNumException::what() const throw()
{
	return ("!! Num is duplicated !!");
}

const char* Span::FullContainerException::what() const throw()
{
	return ("!! Container is Full !!");
}

const char* Span::NotEnoghNumException::what() const throw()
{
	return ("!! Not Enogh Num !!");
}

