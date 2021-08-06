#include "iter.hpp"

// class Awesome
// {
//     public:
//         Awesome( void ) : _n( 42 ) { return; }
//         int get( void ) const { return this->_n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() 
// {
//     int tab[] = { 0, 1, 2, 3, 4 };
//     Awesome tab2[5];
//     iter(tab, 5, print);
//     iter(tab2, 5, print);
//     return 0;
// }

template <typename T>
void iter_print(T const& t)
{
	std::cout << t << std::endl;
}

int main(void)
{
	int arr1[] = {1, 1, 1, 1, 1};
	char arr2[] = "abcdefg";
	std::string arr3[] = {"aaa", "bbb", "ccc", "ddd"};

	iter(arr1, 5, iter_print);

	iter(arr2, 7, iter_print);

	iter(arr3, 4, iter_print);

	return (0);
}