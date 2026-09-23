#pragma once
#include <iostream>
#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter& other);
	public:
		static void		convert(std::string& literal);
		static bool		is_char(std::string& literal);
		static bool		is_int(std::string& literal);
		static bool		is_float(std::string& literal);
		static bool		is_double(std::string& literal);
		static void		to_char(double value);
		static void		to_int(double value);
		static void		to_float(double value);
		static void		to_double(double value);
		static void		pseudo_literals(double value);

};

