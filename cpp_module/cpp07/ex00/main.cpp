#include "whatever.hpp"
#include <iostream>
#include <string>

// class Awesome {

// public:
//     Awesome( int n ) : _n( n ) {}

//     int getN(void) const { return (_n); }
//     bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
//     bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
//     bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
//     bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
//     bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
//     bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
// private:
//     int _n;
// };

// std::ostream & operator<<(std::ostream & os, const Awesome & src)
// {
//     os << src.getN(); return (os);
// }

int main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// Awesome x(42);
	// Awesome y(4242);

	// ::swap(x, y);
	// std::cout << "x = " << x << ", y = " << y << std::endl;
	// std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	// std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
	
	return 0;
}