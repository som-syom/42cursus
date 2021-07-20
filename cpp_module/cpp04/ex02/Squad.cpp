#include "Squad.hpp"

Squad::Squad()
{
	this->count = 0;
	this->unit = 0;
}

Squad::~Squad()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->unit[i];
	}
}

Squad::Squad(Squad const& origin)
{
	*this = origin;
}

Squad& Squad::operator=(Squad const& origin)
{
	if (this->unit)
	{
		for (int i = 0; i < this->count; i++)
			delete this->unit[i];
		delete[] this->unit;
		this->unit = 0;
		this->count = 0;
	}
	this->count = origin.count;
	this->unit = new ISpaceMarine*[origin.count];
	for (int i = 0; i < origin.count; i++)
		this->unit[i] = origin.unit[i]->clone();
	return (*this);
}

int Squad::getCount() const
{
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int n) const
{
	if (n < 0 || this->count == 0 || n > this->count)
		return (0);
	return (this->unit[n]);
}

int Squad::push(ISpaceMarine* marine)
{
	if (marine == 0)
		return (this->count);
	for (int i = 0; i < count; i++)
	{
		if (this->unit[i] == marine)
			return (this->count);
	}
	ISpaceMarine** new_unit = new ISpaceMarine*[this->count + 1];
	for (int i = 0; i < this->count; i++)
		new_unit[i] = this->unit[i];
	new_unit[this->count] = marine;
	delete[] this->unit;
	this->unit = new_unit;
	this->count++;
	return (this->count);
}

