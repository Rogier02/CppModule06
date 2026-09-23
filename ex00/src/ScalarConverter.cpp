#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {
	std::cout << "Scalar default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "Scalar copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Scalar default destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "Scalar Assignment operator called" << std::endl;
	return *this;
}

void	ScalarConverter::convert(std::string& literal) {
	
	double value;

	if (is_char(literal))
		value = static_cast<double>(literal[0]);
	else if (is_int(literal)){
		char *end;
		long parsed = std::strtol(literal.c_str(), &end, 10);
		value = static_cast<double>(parsed);
	}
	else if (is_float(literal)) {
		if (literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else {
			char *end;
			float parsed = std::strtof(literal.c_str(), &end);
			value = static_cast<double>(parsed);	
		}
	}
	else if (is_double(literal)) {
		if (literal == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else if (literal == "-inf")
			value = -std::numeric_limits<double>::infinity();
		else {
			char *end;
			double parsed = std::strtod(literal.c_str(), &end);
			value = static_cast<double>(parsed);
		}
	}
	to_char(value);
	to_int(value);
	to_float(value);
	to_double(value);
}

bool	ScalarConverter::is_char(std::string& literal) {
 	if (literal.length() == 1 &&
		!std::isdigit(static_cast<unsigned char>(literal[0])))
			return true;
	return false;
}

bool	ScalarConverter::is_int(std::string& literal) {
	if (literal.empty())
		return false;		
	char *end;
	long val = std::strtol(literal.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (val < INT_MIN || val > INT_MAX)
		return false;
	return true;
}

bool	ScalarConverter::is_float(std::string& literal) {
	char *end;
	float val = std::strtof(literal.c_str(), &end);

	// nothing was parsed at all
	if (end == literal.c_str())
		return false;
	
	// checks if leftover isn't exactly "f" at the end
	if (*end != 'f' || *(end + 1) != '\0')
		return false;
	return true;
}

bool	ScalarConverter::is_double(std::string& literal) {
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	
	char *end;
	double val = std::strtod(literal.c_str(), &end);

	if (literal.find('.') == std::string::npos || end == literal.c_str())
		return false;
	if (*end != '\0')
		return false;
	return true;
}

void	ScalarConverter::to_char(double value) {
	if (std::isnan(value) 
		|| std::isinf(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(value))))
			std::cout << "Non displayable" << std::endl;
	else 
		std::cout << static_cast<char>(value) << std::endl;
}

void	ScalarConverter::to_int(double value) {
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::to_float(double value) {
	
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
	else {
		float f = static_cast<float>(value);
		if (f == std::floor(f))
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
}

void	ScalarConverter::to_double(double value) {

}

void	ScalarConverter::pseudo_literals(double value) {

}