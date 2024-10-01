#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
// int main(void)
// {
// 	Fixed a(10);
// 	Fixed b(20.4f);
// 	Fixed c;


// 	std::cout << "----------=VALUE=----------" << std::endl;

// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "c = " << c << std::endl;

// 	std::cout << "\n---------=COMPARE=---------" << std::endl;

// 	std::cout << "a > b = " << (a > b) << std::endl;
// 	std::cout << "a < b = " << (a < b) << std::endl;
// 	std::cout << "a >= b = " << (a >= b) << std::endl;
// 	std::cout << "a <= b = " << (a <= b) << std::endl;
// 	std::cout << "a == b = " << (a == b) << std::endl;
// 	std::cout << "a != b = " << (a != b) << std::endl;

// 	std::cout << "\n--------=OPERATORS=--------" << std::endl;
// 	c = a + b;
// 	std::cout << "a + b = " << c << std::endl;
// 	c = a - b;
// 	std::cout << "a - b = " << c << std::endl;
// 	c = a * b;
// 	std::cout << "a * b = " << c << std::endl;
// 	c = a / b;
// 	std::cout << "a / b = " << c << std::endl;

// 	return 0;
// }

