#include "Fixed.hpp"

int main(void)
{
	double a = 0.1;
	float b =0.2;
	while (b != 2)
	{
		b += a;
		std::cout << b << std::endl;
	}

}
