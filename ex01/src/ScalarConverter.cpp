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

void	ScalarConverter::convert(std::string& literal) {

}

bool	ScalarConverter::is_char(std::string& literal) {

}

bool	ScalarConverter::is_int(std::string& literal) {

}

bool	ScalarConverter::is_float(std::string& literal) {

}

bool	ScalarConverter::is_double(std::string& literal) {

}

void	ScalarConverter::to_char(std::string& literal) {

}

void	ScalarConverter::to_int(std::string& literal) {

}

void	ScalarConverter::to_float(std::string& literal) {

}

void	ScalarConverter::to_double(std::string& literal) {

}

void	ScalarConverter::pseudo_literals(std::string& literal) {

}