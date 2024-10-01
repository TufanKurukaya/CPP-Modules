#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << "a is " << a.getRawBits() << " as integer" << std::endl;
	std::cout << "b is " << b.getRawBits() << " as integer" << std::endl;
	std::cout << "c is " << c.getRawBits() << " as integer" << std::endl;
	std::cout << "d is " << d.getRawBits() << " as integer" << std::endl;

	return 0;
}
