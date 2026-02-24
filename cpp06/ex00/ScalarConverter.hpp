#pragma once

#include <string>
// #include "utils.hpp"

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(std::string& s);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter&	operator=(const ScalarConverter& copy);
};