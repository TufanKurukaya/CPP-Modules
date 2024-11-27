#include "ScalarConverter.hpp"
#include <errno.h>

void ScalarConverter::convert(const string &input)
{
	if (!isValidFloat(input) && !isValidInt(input))
	{
		std::cout << "Invalide convert" << std::endl;
		return ;
	}

	if (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
	{
		std::cout << "char: '" << static_cast<char>(input[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
		return ;
	}
	if ((isValidInt(input) || isValidFloat(input)) && !(std::atoi(input.c_str()) > 127 || std::atoi(input.c_str()) < -128)) {
		int asInt = std::atoi(input.c_str());
		if (std::isprint(asInt)) {
			std::cout << "char: '" << static_cast<char>(asInt) << "'" << std::endl;
		}
		else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	// Dönüşüm: int
	if ((isValidInt(input) || isValidFloat(input)) && !(std::atol(input.c_str()) > std::numeric_limits<int>::max() || std::atol(input.c_str()) < std::numeric_limits<int>::min())) {
		int asInt = std::atoi(input.c_str());
		std::cout << "int: " << asInt << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}

	// Dönüşüm: float
	if (isValidFloat(input)) {
		float asFloat = std::strtof(input.c_str(), NULL);
		if (errno == ERANGE) {
			std::cout << "float: impossible" << std::endl;
		} else {
			std::cout << std::fixed << std::setprecision(1)
						<< "float: " << asFloat << "f" << std::endl;
		}
	} else {
		std::cout << "float: impossible" << std::endl;
	}

	// Dönüşüm: double
	if (isValidFloat(input)) {
		double asDouble = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE) {
			std::cout << "double: impossible" << std::endl;
		} else {
			std::cout << std::fixed << std::setprecision(1)
						<< "double: " << asDouble << std::endl;
		}
	} else {
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isValidInt(const std::string &str)
{
		if (str.empty())
			return false;
		size_t i = 0;
		if (str[0] == '-' || str[0] == '+')
			i = 1;
		for (; i < str.length(); ++i) {
			if (!std::isdigit(str[i]))
				return false;
		}
		return true;
}
bool ScalarConverter::isValidFloat(const std::string &str)
{
	char *endPtr;
	double inf_or_nan = std::strtod(str.c_str(), &endPtr);
	if (std::isinf(inf_or_nan) || std::isnan(inf_or_nan))
	{
		if (endPtr != str.c_str() && (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0')))
			return true;
	}
	return endPtr != str.c_str() && (*endPtr == '\0' || ((*endPtr == 'f' && *(endPtr + 1) == '\0')));
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
