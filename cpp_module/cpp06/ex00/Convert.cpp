#include "Convert.hpp"

Convert::Convert()
{
}

Convert::Convert(std::string const& input)
{
	this->_input = input;
}

Convert::~Convert()
{
}

Convert::Convert(Convert const& origin)
{
	*this = origin;
}

Convert& Convert::operator=(Convert const& origin)
{
	this->_input = origin._input;
	this->_c = origin._c;
	this->_i = origin._i;
	this->_f = origin._f;
	this->_d = origin._d;
	return (*this);
}

void Convert::printChar()
{
	std::cout << "char: ";
	std::istringstream iss(this->_input);
	int tmp;

	iss >> tmp;
	this->_c = tmp;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else if (!isprint(this->_c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << this->_c << "'" << std::endl;
}

void Convert::printInt()
{
	std::istringstream iss(this->_input);

	std::cout << "int: ";
	iss >> this->_i;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->_i << std::endl;
}

void Convert::printFloat()
{
	std::cout << "float: ";
	this->_d = stod(this->_input);
	this->_f = static_cast<float>(this->_d);
	std::cout << this->_f;
	if (this->_d == static_cast<int>(this->_d))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void Convert::printDouble()
{
	std::cout << "double: " << this->_d;
	if (this->_d == static_cast<int>(this->_d))
		std::cout << ".0";
	std::cout << std::endl;
}

void Convert::printAll()
{
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

