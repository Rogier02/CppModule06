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
		bool			is_char(std::string& literal);
		bool			is_int(std::string& literal);
		bool			is_float(std::string& literal);
		bool			is_double(std::string& literal);
		void			to_char(std::string& literal);
		void			to_int(std::string& literal);
		void			to_float(std::string& literal);
		void			to_double(std::string& literal);
		void			pseudo_literals(std::string& literal);

};

