#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "------------------------" << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	if (a < b)
		std::cout << "a < b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	
	std::cout << "------------------------" << std::endl;
	Fixed c(10.13f);
	Fixed d(10.12f);

	std::cout << "c   = " << c << std::endl;
	std::cout << "++c = " << ++c << std::endl;
	std::cout << "c   = " << c << std::endl;
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "c   = " << c << std::endl;
	std::cout << "--c = " << --c << std::endl;
	std::cout << "c   = " << c << std::endl;
	std::cout << "c-- = " << c-- << std::endl;
	std::cout << "c   = " << c << std::endl;

	std::cout << "------------------------" << std::endl;
	std::cout << "c     = " << c << std::endl;
	std::cout << "d     = " << d << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;

	return 0;
}