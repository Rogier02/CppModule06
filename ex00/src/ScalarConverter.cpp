#include "ScalarConverter.hpp"

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
}

Static void	ScalarConverter::convert(std::string& literal) {
	
}

static bool	ScalarConverter::is_char(std::string& literal) {

}

static bool	ScalarConverter::is_int(std::string& literal) {
	if (literal.empty())
		return false;		
	char *end;
	long val = std::strtol(literal.c_string(), &end, 10);
	if (*end != '\0')
		return false;
	if (val < INT_MIN || val > INT_MAX)
		return false;
	return true;
}

static bool	ScalarConverter::is_float(std::string& literal) {

}

static bool	ScalarConverter::is_double(std::string& literal) {

}

static void	ScalarConverter::to_char(std::string& literal) {

}

static void	ScalarConverter::to_int(std::string& literal) {

}

static void	ScalarConverter::to_float(std::string& literal) {

}

static void	ScalarConverter::to_double(std::string& literal) {

}

static void	ScalarConverter::pseudo_literals(std::string& literal) {

}